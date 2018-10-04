// Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
// The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.
//
// Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time
class f implements Comparable<f> {
    int priority;
    int key;
    int value;
    f(int a,int b,int prio)
    {
        priority=prio;
        key=a;
        value=b;
    }

    @Override
    public int compareTo(f o) {
        // TODO Auto-generated method stub
        if(o.priority==this.priority)
        {
            return o.key-this.key;
        }
        return this.priority-o.priority;

    }
}
public class Solution {
    TreeSet<f> ne;
    int pr;
    int max;
    HashMap<Integer,f> hm;
    public Solution(int capacity) {
        ne=new TreeSet<f>();
        pr=0;
        max=capacity;
        hm=new HashMap<Integer,f>();
    }

    public int get(int key) {
        if(hm.containsKey(key))
        {
            f g=hm.get(key);
            ne.remove(g);
            g.priority=pr++;
            ne.add(g);
            return g.value;
//            f g=hm.get(key);
//            g.priority=pr++;
//            return g.value;
        }
        else
        {
            return -1;
        }
    }

    public void set(int key, int value) {
        //System.out.println(ne.size()+"> "+hm.size()+" "+key+" "+value);
        if(ne.size()==max && !hm.containsKey(key))
        {
            int ke=ne.pollFirst().key;
        //    System.out.println(ke+"~");
            hm.remove(ke);

        }
        {
            if(hm.containsKey(key))
            {

                f g=hm.get(key);
                ne.remove(g);
                g.priority=pr++;
                g.value=value;
                ne.add(g);
            }
            else
            {
                f vall=new f(key,value,pr++);
                hm.put(key, vall);

                ne.add(vall);


            }
        }
    }
}
