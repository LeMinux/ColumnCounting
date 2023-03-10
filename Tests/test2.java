//This class will hold operation that can be done to arrays
public class ArrayOperations {
    
	//method for adding two MakeArrays together of any size
    public static int [] addArray(MakeArray array1, MakeArray array2){
        int [] sum;
        
        //this if statement is made to avoid a null point error
        if (array1.getNumbersLength() >= array2.getNumbersLength()){
        	//this statement executes when array1 is greater than or equal to array2
            sum = new int[array1.getNumbersLength()];
            
            for(int k = 0; k < array2.getNumbersLength(); k++){
                sum[k] = array1.getNumbersIndex(k) + array2.getNumbersIndex(k);
            }
            
            for(int k = array2.getNumbersLength(); k < array1.getNumbersLength(); k++) {
            	sum [k] = array1.getNumbersIndex(k);
            }
        }else{
        	//this statement executes when array 1 is less than array 2
            sum = new int[array2.getNumbersLength()];
            
            for(int k = 0; k < array1.getNumbersLength(); k++){
                sum[k] = array1.getNumbersIndex(k) + array2.getNumbersIndex(k);
            }
        
            for(int k = array1.getNumbersLength(); k < array2.getNumbersLength(); k++) {
            	sum [k] = array2.getNumbersIndex(k);
            }
            
            
        }
        return sum;
    }
    
    
    //overloaded method for adding two arrays together of any size
    public static int [] addArray(int [] array1, int[] array2){
        int larger = 0;
        int smaller = 0;
        int [] sum;
        
        //this if statement is made to avoid a null point error
        if (array1.length >= array2.length){
            smaller = array2.length;
            larger = array1.length;
            sum = new int[array1.length];
            
            for(int k = 0; k < smaller; k++){
                sum[k] = array1[k] + array2[k];
            }
            
            for(int k = smaller; k < larger; k++) {
            	sum [k] = array1[k];
            }
        }else{
            smaller = array1.length;
            larger = array2.length;
            sum = new int[array2.length];
            
            for(int k = 0; k < smaller; k++){
                sum[k] = array1[k] + array2[k];
            }
        
            for(int k = smaller; k < larger; k++) {
            	sum [k] = array2[k];
            }  
        }
        return sum;
    }
    
  //overloaded method for adding two double arrays together of any size
    public static double [] addArray(double [] array1, double[] array2){
        int larger = 0;
        int smaller = 0;
        double [] sum;
        
        //this if statement is made to avoid a null point error
        if (array1.length >= array2.length){
            smaller = array2.length;
            larger = array1.length;
            sum = new double[array1.length];
            
            for(int k = 0; k < smaller; k++){
                sum[k] = array1[k] + array2[k];
            }
            
            for(int k = smaller; k < larger; k++) {
            	sum [k] = array1[k];
            }
        }else{
            smaller = array1.length;
            larger = array2.length;
            sum = new double[array2.length];
            
            for(int k = 0; k < smaller; k++){
                sum[k] = array1[k] + array2[k];
            }
        
            for(int k = smaller; k < larger; k++) {
            	sum [k] = array2[k];
            }  
        }
        return sum;
    }
    
  //method for subtracting two MakeArrays together of any size
    public static int [] subtractArray(MakeArray array1, MakeArray array2){
        int [] difference;
        
        //this if statement is made to avoid a null point error
        if (array1.getNumbersLength() >= array2.getNumbersLength()){
        	//this statement executes when array1 is greater than or equal to array2
            difference = new int[array1.getNumbersLength()];
            
            for(int k = 0; k < array2.getNumbersLength(); k++){
                difference[k] = array1.getNumbersIndex(k) - array2.getNumbersIndex(k);
            }
            
            for(int k = array2.getNumbersLength(); k < array1.getNumbersLength(); k++) {
            	difference [k] = array1.getNumbersIndex(k);
            }
        }else{
        	//this statement executes when array 1 is less than array 2
            difference = new int[array2.getNumbersLength()];
            
            for(int k = 0; k < array1.getNumbersLength(); k++){
                difference[k] = array1.getNumbersIndex(k) - array2.getNumbersIndex(k);
            }
        
            for(int k = array1.getNumbersLength(); k < array2.getNumbersLength(); k++) {
            	difference [k] = array2.getNumbersIndex(k);
            }     
        }
        return difference;
    }
    
  //overloaded method for subtracting two int arrays together of any size
    public static int [] subtractArray(int [] array1, int[] array2){
        int [] difference;
        
        //this if statement is made to avoid a null point error
        if (array1.length >= array2.length){
            difference = new int[array1.length];
            
            for(int k = 0; k < array2.length; k++){
                difference[k] = array1[k] + array2[k];
            }
            
            for(int k = array2.length; k < array1.length; k++) {
            	difference[k] = array1[k];
            }
        }else{
            difference = new int[array2.length];
            
            for(int k = 0; k < array1.length; k++){
                difference[k] = array1[k] + array2[k];
            }
        
            for(int k = array1.length; k < array2.length; k++) {
            	difference [k] = array2[k];
            }  
        }
        return difference;
    }
    
  //overloaded method for subtracting two double arrays together of any size
    public static double [] subtractArray(double [] array1, double[] array2){
        double [] difference;
        
        //this if statement is made to avoid a null point error
        if (array1.length >= array2.length){
            difference = new double[array1.length];
            
            for(int k = 0; k < array2.length; k++){
                difference[k] = array1[k] + array2[k];
            }
            
            for(int k = array2.length; k < array1.length; k++) {
            	difference[k] = array1[k];
            }
        }else{
            difference = new double[array2.length];
            
            for(int k = 0; k < array1.length; k++){
                difference[k] = array1[k] + array2[k];
            }
        
            for(int k = array1.length; k < array2.length; k++) {
            	difference [k] = array2[k];
            }  
        }
        return difference;
    }
    
}
