#ifndef _VIEW_
#define _VIEW_

#include<vector>
#include "types.hpp"
#include "Pool.hpp"


namespace afp{

    template<typename C1, typename C2>
    struct ViewElement{

        EntityID entity;
        C1& first;
        C2& second;

        ViewElement(EntityID eid, C1& c1, C2& c2): entity(eid), first(c1), second(c2){}
    };

    template<typename View>
    class ViewIterator
    {
        using ValueType1 = typename View::ValueType1;
        using ValueType2 = typename View::ValueType2;
        using Proxy = ViewElement<ValueType1, ValueType2>;

        public:
            ViewIterator(Pool<ValueType1>* p1, Pool<ValueType2>* p2, std::size_t idx = 0): base(p1), other(p2), index(idx){
                skipToNextValid();
            }

            ViewIterator& operator++(){
                advanceToNextValid();
                return *this;
            }

            Proxy operator*(){

                EntityID eid = base->getEntityAt(index);

                return ViewElement<ValueType1, ValueType2>{
                    eid,
                    base->get(eid),
                    other->get(eid)
                };

            }

            bool operator==(const ViewIterator& view){
                return view.index == index && view.base == base && view.other == other;
            }

            bool operator!=(const ViewIterator& view){
                return !( *this == view);
            }

        private:

            void advanceToNextValid(){
                index++;
                skipToNextValid();
            }

            void skipToNextValid(){
                while( index < base->size() && !other->contains(base->getEntityAt(index))){
                    index++;
                }
            }
        private:
            Pool<ValueType1>* base;
            Pool<ValueType2>* other;

            std::size_t index;
    };

    template<typename T1, typename T2>
    class View{
        public:

            using Iterator = ViewIterator<View<T1, T2>>;
            using ValueType1 = T1;
            using ValueType2 = T2;

        public:
            View() = delete;
            View(Pool<T1>* p1, Pool<T2>* p2): base(p1), other(p2){}

            Iterator begin(){

                Iterator it{base, other, 0};
                
                return it;

            }

            Iterator end(){

                Iterator it{base, other, base->size()};
                
                return it;

            }

        private:
            Pool<T1>* base;
            Pool<T2>* other;
    };
}

#endif