class bubbleSort {

    public static void main(String[] args) {
        int a[] = { 36, 19, 29, 12, 5 };

        // make temporary space for sorting 1 number to another space
        int temp;

        // using flag for time complexity
        int flag = 0;

        for (var i = 0; i < a.length; i++) {

            // put -i for time complexity
            for (var j = 0; j < a.length - i - 1; j++) {

                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    flag = 1;
                }
            }

            if (flag == 0) {
                break;
            }

        }
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
}
