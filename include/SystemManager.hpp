#ifndef _SYSTEM_MANAGER_
#define _SYSTEM_MANAGER_

#include<type_traits>
#include<ecs/Registry.hpp>
#include<systems/SystemBase.hpp>

namespace afp{

    #if __cplusplus >= 202002L 
    template<typename T>
    concept System = std::is_base_of_v<SystemBase, T>;
    #endif
    

    class SystemManager{

        public:

            SystemManager() = default;

            void updateAllSystems(Registry& registry, float delta){

                for( auto& system: m_Systems){
                    system->update(registry, delta);
                }

            }

            template<typename T, typename... Args>
            #if __cplusplus >= 202002L 
            requires System<T>
            #endif
            void pushSystem(Args&& ... args){

                #if __cplusplus < 202002L
                static_assert(std::is_base_of<SystemBase, T>::value, "Error, los sistemas deben heredar de SystemBase");
                #endif

                m_Systems.emplace_back(std::make_unique<T>(args...));

            }

            void eraseSystem(){
                /**
                 * Aqui la verdad que no tengo claro como hacerlo, quizás un id includo en SystemBase que sirva para identificarlos...
                 */
            }

        private:

            std::vector<std::unique_ptr<SystemBase>> m_Systems;
            
    };

}
#endif 