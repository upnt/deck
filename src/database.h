#ifndef DATABASE_H
#define DATABASE_H

template<typename T>
class Database {
    public:
    virtual T load(int id){ return T(); }
    virtual size_t size(){ return 0; }
    virtual void print(){}
};

#endif
