/*
https://practice.geeksforgeeks.org/problems/lru-cache/1
Tags: Hash, Queue, Design-Pattern
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedHashMap;
import java.util.Map;

public class LRUDesign {

    public static void main(String[] args) throws IOException {
        BufferedReader read =
                new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            int capacity = Integer.parseInt(read.readLine());
            int queries = Integer.parseInt(read.readLine());
            LRUCache cache = new LRUCache(capacity);
            String str[] = read.readLine().trim().split(" ");
            int len = str.length;
            int itr = 0;

            for (int i = 0; (i < queries) && (itr < len); i++) {
                String queryType = str[itr++];
                if (queryType.equals("SET")) {
                    int key = Integer.parseInt(str[itr++]);
                    int value = Integer.parseInt(str[itr++]);
                    cache.set(key, value);
                }
                if (queryType.equals("GET")) {
                    int key = Integer.parseInt(str[itr++]);
                    System.out.print(cache.get(key) + " ");
                }
            }
            System.out.println();
        }
    }

    // design the class in the most optimal way
    static class LRUCache {

        private final int cap;
        private final Map<Integer,Integer> lru;

        //Constructor for initializing the cache capacity with the given value.
        LRUCache(int cap) {
            //code here
            this.cap = cap;
            lru = new LinkedHashMap<>();
        }

        //Function to return value corresponding to the key.
        public int get(int key) {
            Integer value = lru.get(key);
            if(value == null) return -1;
            lru.remove(key);
            lru.put(key,value);
            return value;
        }

        //Function for storing key-value pair.
        public void set(int key, int value) {
            // your code here
            if(lru.get(key) != null)
                lru.remove(key);

            if(lru.size() >= this.cap)
                lru.remove(lru.keySet().iterator().next());

            lru.put(key,value);
        }
    }

}


