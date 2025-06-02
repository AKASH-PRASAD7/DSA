#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Heap{

    bool isMin;
    vector<int> heap;

    public:
        Heap(bool isMin){

            // this->heap.resize(size,-1);
            this->isMin = isMin;
        }

        void resturctureHeapAfterInsert(){

            if(isMin){
                /**
                 * @brief For min heap
                 * parent <= cuurent Item
                 * 
                 * - From last item check if parent > current
                 * - keep swapping and update current if condition satisfies
                 * 
                 */

                 int currentIdx =  heap.size()-1;

                 //parent = curr / 2

                 while(heap[currentIdx/2] > heap[currentIdx]){
                    int temp = heap[currentIdx];
                    heap[currentIdx] = heap[currentIdx/2];
                    heap[currentIdx/2] = temp;

                    //update cuurent
                    currentIdx = currentIdx/2;
                 }

            }else{

                /**
                 * @brief For max heap
                 * parent >= cuurent Item
                 * 
                 * - From last item check if parent < current
                 * - keep swapping and update current if condition satisfies
                 * 
                 */

                 int currentIdx =  heap.size()-1;

                 //parent = curr / 2

                 while(heap[currentIdx/2] < heap[currentIdx]){
                    int temp = heap[currentIdx];
                    heap[currentIdx] = heap[currentIdx/2];
                    heap[currentIdx/2] = temp;

                     //update cuurent
                     currentIdx = currentIdx/2;
                 }

            }
        }

        void resturctureHeapAfterDelete(){
            if(isMin){
                /**
                 * @brief For min heap
                 * 
                 * left = curr *2, right = (curr*2) + 1
                 * 
                 * (treating -1 as empty val/null)
                 * - replace root/first with last
                 * - now check if left/right of root is < root
                 * - if yes swapp with the lesser one
                 * -  and keep swapping until condition satifies
                 * 
                 */

                int currentIdx =  heap.size()-1;

                //replace with root
                heap[1] = heap[currentIdx];
                currentIdx = 1;

                int leftIdx = currentIdx * 2;
                int rightIdx = (currentIdx * 2) + 1;


                while(heap[leftIdx] < heap[currentIdx] || heap[rightIdx] < heap[currentIdx]){
                    int temp;
                    if(heap[leftIdx] < heap[currentIdx]){
                        temp = heap[currentIdx];
                        heap[currentIdx] = heap[leftIdx];
                        heap[leftIdx] = temp;

                        //update current,left,right
                        currentIdx = leftIdx;
                        leftIdx = currentIdx * 2;
                        rightIdx = (currentIdx * 2) + 1;
                    }else{
                        temp = heap[currentIdx];
                        heap[currentIdx] = heap[rightIdx];
                        heap[rightIdx] = temp;

                        //update current,left,right
                        currentIdx = rightIdx;
                        leftIdx = currentIdx * 2;
                        rightIdx = (currentIdx * 2) + 1;

                    }

                }

            }else{
                /**
                 * @brief For max heap
                 * 
                 * left = curr *2, right = (curr*2) + 1
                 * 
                 * (treating -1 as empty val/null)
                 * - replace root/first with last
                 * - now check if left/right of root is > root
                 * - if yes swapp with the lesser one
                 * -  and keep swapping until condition satifies
                 * 
                 */

                 int currentIdx =  heap.size()-1;
                 //replace with root
                heap[1] = heap[currentIdx];
                currentIdx = 1;

                 int leftIdx = currentIdx * 2;
                 int rightIdx = (currentIdx * 2) + 1;
 
                 while(heap[leftIdx] > heap[currentIdx] || heap[rightIdx] > heap[currentIdx]){
                     int temp;
                     if(heap[leftIdx] > heap[currentIdx]){
                         temp = heap[currentIdx];
                         heap[currentIdx] = heap[leftIdx];
                         heap[leftIdx] = temp;
 
                         //update current.left,right
                         currentIdx = leftIdx;
                         leftIdx = currentIdx * 2;
                        rightIdx = (currentIdx * 2) + 1;
                     }else{
                         temp = heap[currentIdx];
                         heap[currentIdx] = heap[rightIdx];
                         heap[rightIdx] = temp;
 
                         //update current,left,right
                        currentIdx = rightIdx;
                        leftIdx = currentIdx * 2;
                        rightIdx = (currentIdx * 2) + 1;
 
                     }
 
                 }

            }
        }

        void insert(int val){
            //skip 0 index
            if(heap.size()){
                heap.push_back(val);
            }else{
                
                heap.push_back(-1); // inserting -1 at 0
                heap.push_back(val);
            }
            //upheap
            resturctureHeapAfterInsert();
        }
        
        void deleteItem(){
            // using -1 as empty value
            heap[1] = -1;
            
            //down heap
            resturctureHeapAfterDelete();
        }

        void print(){
            for(int i =1; i<heap.size(); i++){
                cout<<heap[i]<<", ";
            }
        }

        void top(){
            cout<<heap[1];
        }

    
   

};

int main(){
    Heap min(false);

    min.insert(7);
    min.insert(4);
    min.insert(6);
    min.insert(2);
    min.insert(1);
    min.insert(11);
    min.insert(12);

    min.top();
    cout<<endl;
    min.print();
    cout<<endl;
    min.deleteItem();
    min.deleteItem();
    min.deleteItem();
    min.top();
}