import java.util.Scanner;

public class BinarySearch {
    static int binarySearch(int[] arr, int target){
        int start = 0, end = arr.length - 1;

        //assumin the array is sorted in ascending order
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(arr[mid] == target)
                return mid;
            if(target > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);

        System.out.println("Enter the size of the array: ");
        int n = obj.nextInt();

        System.out.println("Enter the array in ascending order: ");
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = obj.nextInt();
        }

        System.out.println("Enter the number to be searched: ");
        int num = obj.nextInt();

        int res = binarySearch(arr, num);
        if(res == -1)
            System.out.println("The given number is NOT in the array");
        else
            System.out.println("The given number is at idx " + res + " in the given array");
    }
}