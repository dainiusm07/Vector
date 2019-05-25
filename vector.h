#ifndef VECTOR_H
#define VECTOR_H

#include "header.h"

template <class T>
class Vector{
    private:
    size_t vector_size;
    size_t vector_cap;
    T* vector_elem;

    public:
    typedef size_t size_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    
    ~Vector () { delete[] vector_elem; };
    Vector () { vector_size = vector_cap = 0; vector_elem = 0; };
    Vector (size_t size){ vector_size = vector_cap = size; vector_elem = new T[size]; };
    Vector (size_t size, const_reference elem) {
    vector_size = vector_cap = size;
    vector_elem = new T[size];
    for (int i = 0; i < size; i++)
        vector_elem[i] = elem;
    };
    Vector(Vector&& temp) : vector_size { temp.vector_size }, vector_cap { temp.vector_cap } {
        vector_elem = temp.vector_elem;
        temp.vector_elem = nullptr;
        temp.vector_size = temp.vector_cap = 0;
    };
    Vector (const Vector<T>& temp){
    vector_size = temp.vector_size;
    vector_cap = temp.vector_cap;
    vector_elem = new T[vector_size];
    for (int i = 0; i < vector_size; i++)
        vector_elem[i] = temp.vector_elem[i];
    };
    Vector (iterator first, iterator last) {
        vector_size = vector_cap = 0;
        vector_elem = 0;
        while (first != last){
            push_back(*first);
            first++;
        }
    };

    // Reference

    reference at (size_t pos) {
        if (!(pos < vector_size)) throw std::out_of_range("Element is out of range!");
        return vector_elem[pos];
    }
    reference front() {
        if (vector_size == 0) throw std::out_of_range("Empty vector!");
        return vector_elem[0];
    }
    reference back() {
        if (vector_size == 0) throw std::out_of_range("Empty vector!");
        return vector_elem[vector_size - 1];
    }

    // Iteratoriai

    iterator begin() {
        if (vector_size == 0) throw std::out_of_range("Empty vector!");
        return vector_elem;
    }
    iterator end() {
        if (vector_size == 0) throw std::out_of_range("Empty vector!");
        return vector_elem + vector_size;
    }
    iterator rbegin() {
        if (vector_size == 0) throw std::out_of_range("Empty vector!");
        return vector_elem + vector_size;
    }
    iterator rend() {
        if (vector_size == 0) throw std::out_of_range("Empty vector!");
        return vector_elem;
    }
    iterator data() noexcept{
        return vector_elem;
    }

    // Operatoriai
    reference operator[](int pos) {
        if (!(pos < vector_size)) throw std::out_of_range("Element is out of range!");
        return vector_elem[pos];
    }

    Vector& operator=(const Vector& temp) {
        if (&temp == this) return *this;

        iterator new_elem = new T[temp.vector_size]; 
        std::move(&temp.vector_elem[0], &temp.vector_elem[temp.vector_size], new_elem);
        delete[] vector_elem;
        vector_elem = new_elem;
        vector_size = temp.vector_size;
        vector_cap = temp.vector_cap;
        return *this;
    }

    bool operator==(const Vector<T>& temp){
        if (vector_size == temp.vector_size and vector_cap == temp.vector_cap){
            for (int i=0 ; i<vector_size ; i++)
                if (vector_elem[i] != temp.vector_elem[i]) return false;
            return true;
        }
        return false;
    }
    bool operator!=(const Vector<T>& temp){
        return !operator==(temp);
    }

    bool operator<(const Vector<T>& temp){
        if(empty() && temp.empty()) return false;
        else if (empty()) return true;
        else if (temp.empty()) return false;
        else {
            int i = 0;
            while(vector_elem[i]==temp.vector_elem[i]){
                if((i+1 > vector_size)||(i+1 > temp.vector_size)) break;
                i++;
            }
            if(vector_elem[i] < temp.vector_elem[i]) return true;
            else if(vector_elem[i] == temp.vector_elem[i]){
                if(vector_size < temp.vector_size) return true;
                else return false;
            }
            else return false;
        }
    }

    bool operator>(const Vector<T>& temp){ return !operator>(temp); }

    bool operator<=(const Vector<T>& temp) {
        if (operator<(temp) or operator==(temp)) return true;
        else false;
    }
    bool operator>=(const Vector<T>& temp) { return !operator<=(temp); }

    // Kitos funkc
    size_t size() const { return vector_size; }

    size_t capacity() const { return vector_cap; }

    inline bool empty () const { return vector_size == 0; }

    void clear () { vector_size = 0; delete[] vector_elem; new T[vector_cap]; }

    void push_back (const_reference elem){

        vector_size++;
        if (vector_cap == 0){
            vector_elem = new T;
            vector_cap = 1;
        }
        else if (vector_size > vector_cap) {
            reserve(vector_cap * 2);
        }
        vector_elem[vector_size - 1] = elem;
    }

    void push_front (const_reference elem) {
        vector_size++;
        if (vector_cap == 0){
            vector_elem = new T;
            vector_cap = 1;
        }
        else if (vector_size > vector_cap) {
            reserve(vector_cap * 2);
        }

        std::move(&vector_elem[0], &vector_elem[vector_size - 1], &vector_elem[1]);
        vector_elem[0] = elem;
    }

    void reserve (size_t n){
        if(vector_cap < n) {
            iterator elem = new T[n];
            std::move(&vector_elem[0],&vector_elem[vector_size - 1], elem);
            vector_cap = n;
            if (n == 2)
                delete vector_elem;
            else
                delete[] vector_elem;
            vector_elem = elem;  
        }
    }

    void resize (size_t count) {

        iterator new_elem1 = new T[count];
        if (count < vector_size){

            for (int i = 0 ; i < count ; i++ )
                new_elem1[i] = vector_elem[i];
        }
        else if (count > vector_size) {
            for (int i = 0 ; i < vector_size ; i ++)
                new_elem1[i] = vector_elem[i];
        }

        vector_size = vector_cap = count;
        delete[] vector_elem;
        vector_elem = new_elem1;
    }

    void erase(int i) {
        if (!( i < vector_size )) throw std::out_of_range("Element you want erase is out of range!");
        std::move(&vector_elem[i + 1], &vector_elem[vector_size], &vector_elem[i]);
        vector_size--;
    }

    void erase(iterator first, iterator last) {
        int count = 0;

        while (first != vector_elem){
            first--;
            count++;
        }
        first+=count;
        int count2 = count;

        while (first != last){
            first++;
            count2++;
        }
        std::move(&vector_elem[count2], &vector_elem[vector_size], &vector_elem[count]);
        vector_size-=count2-count;
    }

    void swap(Vector<T> & elem){
        Vector<T> temp;
        temp.vector_elem = new T[elem.vector_size];
        temp.vector_size = elem.vector_size;
        temp.vector_cap = elem.vector_cap;
        std::move(elem.begin(), elem.end(), temp.begin());
        elem.vector_elem = new T[vector_size];
        elem.vector_size = vector_size;
        elem.vector_cap = vector_cap;
        std::move(&vector_elem[0], &vector_elem[vector_size], temp.begin());
        vector_elem = new T[temp.vector_size];
        vector_size = temp.vector_size;
        vector_cap = temp.vector_cap;
        std::move(temp.begin(), temp.end(), vector_elem);
    }

    void insert (size_t pos, const_reference elem){
        if (vector_size<vector_cap){
            std::move(&vector_elem[pos],&vector_elem[vector_size],&vector_elem[pos+1]);
            vector_elem[pos] = elem;
        }
        else {
            reserve(2 * vector_cap);
            insert(pos,elem);
        }
    }

    void emplace_back(const_reference elem) {
        push_back(elem);
    }

    void pop_back() {
        if (vector_size==0) return;
        else resize(vector_size-1);
    }

    void shrink_to_fit(){
        iterator temp = new T[vector_size];
        std::move(&vector_elem[0],&vector_elem[vector_size],temp);
        vector_cap = vector_size;
        delete [] vector_elem;
        vector_elem = temp;
    }

    void assign (size_t count, const_reference elem) {
        resize(count);
        for (int i = 0 ; i < count ; i++ )
            vector_elem[i] = elem;
    }





    
};


#endif // !VECTOR_H
