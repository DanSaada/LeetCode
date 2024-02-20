class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List list = new ArrayList();
        int l = 0, r = arr.length-1;
        while(r - l >= k){
            if(Math.abs(arr[l] - x) <= Math.abs(arr[r] - x)) r--;
            else    l++;
        }

       while(l <= r) {
            list.add(arr[l++]);
        }

        return list;
    }
}


