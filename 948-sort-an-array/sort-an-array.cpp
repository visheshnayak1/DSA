class Solution {
public:
    void merge(vector<int>& nums,int left,int right, int mid) {
        int n1 = mid - left+1;
        int n2 = right-mid;

        vector<int>L(n1),R(n2);
        for(int i = 0 ; i < n1; i++) {
            L[i] = nums[left+i];
        }
        for(int j = 0 ; j < n2 ; j++) {
            R[j] = nums[mid+1+j];
        }

        int i =0;
        int j =0;
        int k = left;
        while(i < n1 && j < n2) {
            if(L[i] < R[j]){
                nums[k] = L[i];
                i++;
            }else{
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }
        while(j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
//     void merge(vector<int>& arr, int left, 
//                      int mid, int right){
                         
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Create temp vectors
//     vector<int> L(n1), R(n2);

//     // Copy data to temp vectors L[] and R[]
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     int i = 0, j = 0;
//     int k = left;

//     // Merge the temp vectors back 
//     // into arr[left..right]
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[], 
//     // if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[], 
//     // if there are any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
    void mergeSort(vector<int>& nums,int left, int right) {
        if(left >= right ) return ;

        int mid = left - (left-right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,right,mid);

    }
//     void mergeSort(vector<int>& arr, int left, int right){
    
//     if (left >= right)
//         return;

//     int mid = left + (right - left) / 2;
//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid + 1, right);
//     merge(arr, left, mid, right);
// }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n-1;

        mergeSort(nums,left,right);
        return nums;
    }
};