package fileencoder61710;

import java.io.File;
import java.util.LinkedList;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.ListIterator;

/**
 *
 * @author Dell
 */
public class FileEncoder61710 {

    public static boolean isPrime(int n) {
        // arbitrary search limit
        int[] primes = {2, 3, 5, 7};
        
        boolean[] isPrime = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            isPrime[i] = true;
        }
        return false;
    }
    
    public static ArrayList<Character> convertToArray(LinkedList<Character> keys) {
        ArrayList<Character> result = new ArrayList();
        ListIterator<Character> iterator = keys.listIterator();
        while(iterator.hasNext()) {
            result.add(iterator.next());
        }
        return result;
    }

    /**
     * Encodes a file with the specified key and saves the result to a given
     * file.
     *
     * @param sourceFile - path to the initial file
     * @param destinationFile - path to the result file
     * @param key - list of replacement bytes
     */
    public static void encode(String sourceFile, String destinationFile, LinkedList<Character> key) {
        ArrayList<Character> result = convertToArray(key);
        try(FileInputStream in = new FileInputStream(new File(sourceFile));
                FileOutputStream out = new FileOutputStream(new File(destinationFile));) {
            int byteCode, index = 0;
            while ((byteCode = in.read()) != -1) {
                if(isPrime(index)) {
                    out.write(byteCode);
                }
                else {
                    out.write(result.get(index));
                }
                index++;
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Decodes a file that was encoded with the above algorithm.
     *
     * @param encodedFile - path to encoded file
     * @param destinationFile - path to the result file
     * @param key - list of replacement bytes that were used to encode the file
     */
    public void decode(String encodedFile, String destinationFile, LinkedList<Character> key) {
//        ArrayList<Character> result = convertToArray(key);
//        try(FileInputStream in = new FileInputStream(new File(encodedFile));
//                FileOutputStream out = new FileOutputStream(new File(destinationFile));) {
//            int byteCode, index = 0;
//            while ((byteCode = in.read()) != -1) {
//                if(isPrime(index)) {
//                    out.write(byteCode);
//                }
//                else {
//                    out.write(result.get(index));
//                }
//                index++;
//            }
//        } catch (IOException e) {
//            System.out.println(e.getMessage());
//        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        isPrime(3);
        LinkedList keys = new LinkedList();
        keys.add('0');
        keys.add('1');
        keys.add('2');
//        File file = new File("read.txt");
//        file.createNewFile();
        
        // doesn't work
        encode(System.getProperty("user.dir") + "\\read.txt", System.getProperty("user.dir") + "\\write.txt", keys);
    }

}
