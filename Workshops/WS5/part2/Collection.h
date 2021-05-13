/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

using namespace std;
namespace sdds
{
    template <typename T>
    class Collection
    {
        string m_name{};
        T *m_item{};
        size_t m_cnt{};
        void (*m_observer)(const Collection<T>&, const T&){nullptr};

    public:
        explicit Collection(const std::string& name)
        {
            m_name = name;
            m_item = nullptr;
            m_cnt = 0;
            m_observer = nullptr;
        }
        Collection(Collection&) = delete;
        Collection&operator=(Collection&) = delete;
        ~Collection(){
            delete [] m_item;
            m_item = nullptr;
        }
        [[nodiscard]] const std::string& name() const
        {
            return m_name;
        }
        [[nodiscard]] size_t size() const
        {
            return m_cnt;
        }
        void setObserver(void (*observer)(const Collection<T>&, const T&))
        {
            m_observer = observer;
        }
        Collection<T>& operator+=(const T& item)
        {
            bool exist = false;

            for (size_t i = 0; i < m_cnt; ++i) 
            {
                if(m_item[i].title() == item.title())
                {
                    exist = true;
                }
            }
            if(!exist)
            {
                if(m_cnt == 0)
                {
                    m_cnt++;
                    m_item = new T[m_cnt];
                    m_item[0] = item;
                }
                else
                {
                    T* temp = new T[m_cnt];
                    for (size_t i = 0; i < m_cnt; ++i)
                    {
                        temp[i] = m_item[i];
                    }
                    delete [] m_item;
                    m_cnt++;
                    m_item = new T[m_cnt];
                    for (size_t j = 0; j < m_cnt-1; ++j) 
                    {
                        m_item[j] = temp[j];
                    }
                    delete [] temp;
                    m_item[m_cnt-1] = item;
                    if(m_observer != nullptr)
                    {
                        m_observer(*this, item);
                    }
                }
            }
            return *this;
        }
        T& operator[](size_t idx) const
        {
            if(idx >= m_cnt || idx < 0)
            {
                throw std::out_of_range("Bad index [" + to_string(idx) + "]. " + "Collection has [" + to_string(m_cnt) + "] items.");
            } 
            else 
            {
                return m_item[idx];
            }
        }
        T* operator[](std::string title) const
        {
            int idx=-1;
            for (size_t i = 0; i < m_cnt; ++i) 
            {
                if(m_item[i].title() == title)
                {
                    idx = i;
                }
            }
            if(idx == -1)
            {
                return nullptr;
            } 
            else 
            {
                return &m_item[idx];
            }
        }

        friend ostream& operator<<(ostream& os, Collection& src)
        {
            for (size_t i = 0; i < src.size(); ++i) 
            {
                os << src.m_item[i];
            }
            return os;
        }
    };
}
#endif