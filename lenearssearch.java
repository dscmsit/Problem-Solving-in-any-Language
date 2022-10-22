public class lenearsearch {
    public static void main(String[] args) {
        int[] nums = { 12, 23, 34, 45, 56, 67, 78, 89 };
        int Target = 56;
        int ans = lenear(nums, Target);
        System.out.println(ans);
    }

    static int lenear(int[] arr, int target) {
        if (arr.length == 0) {
            return -1;
        }

        for (int i = 0; i < arr.length; i++) {
            int element = arr[i];
            if (element == target) {
                return target;

            }
        }
        return -1;

    }

}
