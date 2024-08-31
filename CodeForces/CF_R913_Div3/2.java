import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 注意 hasNext 和 hasNextLine 的区别
        int T = Integer.parseInt(br.readLine());
        for(int i=0;i<T;i++){
            //int len = in.nextInt();
            String text  =br.readLine();
            char[] chars = text.toCharArray();
            int upCount  =0;
            int lowCount = 0;
            StringBuilder ans = new StringBuilder();
            for(int j=text.length()-1;j>=0;j--){
                if(Character.isUpperCase(chars[j]) && chars[j]!='B'){
                    if(upCount>0){
                        upCount--;
                    }
                    else{
                        ans.insert(ans.size(),chars[j]);
                    }
                }
                else if(Character.isLowerCase(chars[j]) && chars[j]!='b'){
                    if(lowCount>0){
                        lowCount--;
                    }
                    else{
                        ans.insert(ans.size(),chars[j]);
                    }
                }
                else if(chars[j] == 'B'){
                    upCount++;
                }
                else if(chars[j] == 'b'){
                    lowCount++;
                }
            }
            ans.reverse();
            System.out.println(ans);
        }
 
    }
}