/*
https://practice.geeksforgeeks.org/problems/common-elements5420/1
Tags: Arrays, Hash
*/

import java.util.*;

public class CommonElements {
    public static void main (String[] args) {

        //taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        //taking total count of testcases
        int t=sc.nextInt();
        while(t-->0)
        {
            //taking total count-1 of elements
            int n=sc.nextInt();

            //Declaring and Initializing an ArrayList-1
            ArrayList<Integer>v1=new ArrayList<>();

            //adding elements to the ArrayList-1
            for(int i=0;i<n;i++)
            {
                v1.add(sc.nextInt());
            }

            //taking total count-2 of elements
            int m=sc.nextInt();

            //Declaring and Initializing an ArrayList-2
            ArrayList<Integer>v2=new ArrayList<>();

            //adding elements to the ArrayList-2
            for(int i=0;i<m;i++)
            {
                v2.add(sc.nextInt());
            }
            //calling the method common_element
            //and passing ArrayList 1, 2 as arguments
            //and storing the results in a new ArrayList
            ArrayList<Integer>ans=solve(v1, v2);

            //printing the elements of the new ArrayList
            for(int i:ans)
                System.out.print(i+" ");

            System.out.println();
        }
    }

    private static ArrayList<Integer> solve(ArrayList<Integer> list1, ArrayList<Integer> list2) {
        //Your code here
        Map<Integer,Integer> map1 = new HashMap<>();
        Map<Integer,Integer> map2 = new HashMap<>();

        for(int element : list1)
            map1.merge(element, 1, Integer::sum);

        for(int element : list2)
            map2.merge(element, 1, Integer::sum);

        ArrayList<Integer> result = new ArrayList<>();
        for(int key : map1.keySet()){
            if(map2.containsKey(key)){
                int count = Math.min(map1.get(key),map2.get(key));
                for(int i=0; i<count; i++)
                    result.add(key);
            }
        }
        Collections.sort(result);
        return result;
    }
}