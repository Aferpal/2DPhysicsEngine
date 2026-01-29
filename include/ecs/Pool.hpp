#ifndef _POOL_
#define _POOL_

#include<vector>
#include "types.hpp"

namespace afp{

    class basic_pool{
        public:
            virtual ~basic_pool() = default;
    };

    template<typename T>
    class Pool : public basic_pool {

        public:
            Pool() = default;

            Pool(const Pool&) = delete;

            Pool(Pool&&) = delete;

            bool contains(EntityID id){

                return id < spare.size() && spare[id] < dense_id.size() && id == dense_id[spare[id]];

            }

            template<typename... Args>
            T& insert(EntityID id, Args&& ... args){

                // this means there have been new entities created, so we resize our spare vector
                if( id >= spare.size() ){

                    spare.resize(id + 1);

                }
                 
                if( contains(id) ){ // in case there is actually an inserted element
                    throw 0;                     // we return, for now the intended functionality is to IGNORE the insertion in this case
                }

                dense_id.emplace_back(id);

                dense_components.emplace_back(std::forward<Args>(args)...);

                spare[id] = dense_id.size() - 1;

                return dense_components.back();

            }

            T& get(EntityID id){

                if( !contains(id) ){ // in case there is actually an inserted element
                    throw 0;         // we return, for now the intended functionality is to IGNORE the insertion in this case
                }  

                return dense_components[spare[id]];

            }

            const T& get(EntityID id) const {
                
                if( !contains(id) ){ // in case there is actually an inserted element
                    throw 0;         // we return, for now the intended functionality is to IGNORE the insertion in this case
                }  

                return dense_components[spare[id]];

            }

            void erase(EntityID id){

                if( contains(id) ){
                    
                    unsigned int index = spare[id];

                    dense_components[index] = dense_components.back();

                    dense_components.pop_back();

                    dense_id[index] = dense_id.back();

                    dense_id.pop_back();

                    spare[dense_id[index]] = index;
                    
                }

            }

            EntityID getEntityAt(std::size_t index){
                if( index < dense_id.size() ){
                    return dense_id[index];
                }else{
                    return -1;
                }
                
            }

            std::size_t size() const{
                return dense_components.size();
            }


        private:

            std::vector<T> dense_components;

            std::vector<EntityID> dense_id;

            std::vector<unsigned int> spare;

    };

}

#endif