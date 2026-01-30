#ifndef _COLLISION_SYSTEM_
#define _COLLISION_SYSTEM_

#include "SystemBase.hpp"
#include <components/Transform.hpp>
#include <components/Dynamic.hpp>
#include<components/Collider.hpp>

namespace afp{

    class CollisionSystem : public SystemBase{

        public:

            virtual void update(Registry& registry, float delta) override {

                for( auto [eid, transform, collider] : registry.view<Transform, Collider>()){
                    
                    // here ideally we call another collision engine

                    // Something linke CollissionEngine.solve( list of colliders and transforms )

                    // Could be a nice idea to have a template or some sort of dependency injection so that users can define their own collision system

                    // We give a simple base class to define a contract and the users can work their own engines

                    // TODO for now

                }

            }

    };

}
#endif