public class Solution {

    public static void main(String[] args) {
    
        System.out.println("Test Data: [0, 1, 0, 3, 12]");
        System.out.println("Expected Output: [1, 3, 12, 0, 0]");

	int[] nums = {0, 1, 0, 3, 12};
	moveZeroes(nums);

	System.out.print("Output: [");
	for(int i = 0; i < nums.length; i++) {
	    System.out.print(nums[i] + ", ");
	}
	System.out.println("]");

    }

    public static void moveZeroes(int[] nums) {

        

        int i = 0;

        

        for(int j = 0; j < nums.length; j++) {

            if(nums[j] != 0) {

                nums[i] = nums[j];

                i++;

            }

        }

        

        while(i < nums.length) {

            nums[i] = 0;

            i++;

        }

        

    }

}
