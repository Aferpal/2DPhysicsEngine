#ifndef _DYNAMIC_SYSTEM_
#define _DYNAMIC_SYSTEM_

#include "SystemBase.hpp"
#include <components/Dynamic.hpp>
#include <components/Transform.hpp>
#include <components/Gravity.hpp>

namespace afp{

    class DynamicSystem : public SystemBase{

        public:

            virtual void update(Registry& registry, float delta) override {

                for( auto [eid, transform, dynamic] : registry.view<Transform, Dynamic>()){

                    Vector2 acc = dynamic.force() * (1/dynamic.mass());

                    dynamic.speed() = dynamic.speed() + acc * delta;

                    transform.position() = transform.position() + dynamic.speed()*delta;

                    // if this entity casually has also gravity we undo the force since we already did our thing
                    if( registry.has<Gravity>(eid) ){

                        dynamic.force() -= registry.get<Gravity>(eid).gravityForce(); 
                    
                    }

                }

            }

    };

}
#endif