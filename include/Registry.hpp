#ifndef _REGISTRY_
#define _REGISTRY_

#include<unordered_map>
#include<Pool.hpp>
#include<memory>
#include<View.hpp>

namespace afp{
    

    using typeId = std::size_t;

    inline typeId next_id() {
        static typeId value = 0;
        return value++;
    }

    template<typename T>
    typeId type_id() {
        static const typeId value = next_id();
        return value;
    }


     
    class Registry{

        public:

            Registry() = default;


            // to emplace components

            template<typename T, typename... Args>
            T& emplace(EntityID id, Args&& ... args){

                return getOrInsertPool<T>().insert(id, args...);

            }


            // to get components from a given entity

            template<typename T>
            T& get(EntityID id){

                Pool<T>& p = getPool<T>();
                return p.get(id);

            }


            template<typename T1, typename T2>
            View<T1, T2> view(){

                Pool<T1>& p1 = getOrInsertPool<T1>();

                Pool<T2>& p2 = getOrInsertPool<T2>();

                return View<T1, T2>(std::addressof(p1), std::addressof(p2));
            }


        private:

            template<typename T>
            Pool<T>& getOrInsertPool(){

                auto tid = type_id<T>();

                if( data.find(tid) == data.end() ){ // if does not exist

                    data.emplace(
                        tid, 
                        std::make_unique<Pool<T>>()
                    );

                }

                return static_cast<Pool<T>&>(*(data.at(tid)));

            }

            template<typename T>
            Pool<T>& getPool(){

                auto tid = type_id<T>();

                return static_cast<Pool<T>&>(*(data.at(tid)));

            }

            template<typename T>
            const Pool<T>& getPool() const {

                auto tid = type_id<T>();

                return static_cast<Pool<T>&>(*(data.at(tid)));

            }

        private:

            std::unordered_map<typeId, std::unique_ptr<basic_pool>> data;

    };

}

#endif