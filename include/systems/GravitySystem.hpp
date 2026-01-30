#ifndef _GRAVITY_SYSTEM_
#define _GRAVITY_SYSTEM_

#include "SystemBase.hpp"
#include <components/Gravity.hpp>
#include <components/Dynamic.hpp>

namespace afp{

    class GravitySystem : public SystemBase{

        public:

            virtual void update(Registry& registry, float delta) override {

                // maybe a more precise gravity system could here calculate the gravity forces created between all gravitational entities
                // and then, later, update all entities dynamics. In other words this is a SimpleGravitySystem that only considers gravity
                // towards the ground, but since this is a completely functional Physics engine, it could be trivial to simply create a new
                // ComplexGravitySystem for space/stars simulations and so on. 

                for( auto [eid, dynamic, gravity] : registry.view<Dynamic, Gravity>()){
                    
                    // essentially, every entity with gravity will increase the force by the gravity
                    dynamic.force() = dynamic.force() + gravity.gravityForce(); 

                }

            }

    };

}
#endif