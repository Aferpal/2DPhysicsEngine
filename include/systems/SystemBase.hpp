#ifndef _SYSTEM_BASE_
#define _SYSTEM_BASE_

#include<ecs/Registry.hpp>

namespace afp{

    class SystemBase{
        public:

            virtual void update(Registry&, float) = 0;

            virtual ~SystemBase() = default;


    };

}

#endif