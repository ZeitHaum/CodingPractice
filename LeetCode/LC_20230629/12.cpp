class Solution {
public:

    string get_multi_str(char c, int num){
        string ret = "";
        for(int i = 0;i<num;i++){
            ret.push_back(c);
        }
        return ret;
    }

    string intToRoman_5(int num){
        if(num==4){
            return "IV";
        }
        else{
            return get_multi_str('I', num);
        }
    }


    string intToRoman_10(int num){
        if(num==9){
            return "IX";
        }
        else{
            if(num>=5){
                return "V" + intToRoman_5(num - 5);
            }
            else{
                return intToRoman_5(num);
            }
        }
    }

    string intToRoman_50(int num){
        string ret  = "";
        if(num>=40){
            ret += "XL";
            return ret + intToRoman_10(num - 40);
        }
        else{
            return get_multi_str('X', num/10) + intToRoman_10(num - (num/10) * 10);
        }
    }

    string intToRoman_100(int num){
        string ret = "";
        if(num>=90){
            ret += "XC";
            return ret + intToRoman_10(num - 90);
        }
        else{
            if(num>=50){
                ret += "L";
                num -=50;
            }
            return ret + intToRoman_50(num);
        }
    }

    string intToRoman_500(int num){
        string ret = "";
        if(num>=400){
            ret += "CD";
            return ret + intToRoman_100(num - 400);
        }
        else{
            return get_multi_str('C', num/100) + intToRoman_100(num - (num/100) * 100);
        }
    }

    string intToRoman_1000(int num){
        string ret = "";
        if(num>=900){
            ret += "CM";
            return ret + intToRoman_100(num - 900);
        }
        else{
            if(num>=500){
                ret +="D";
                num -=500;
            }
            return ret + intToRoman_500(num);
        }
    }


    string intToRoman(int num) {
        string ret = "";
        if(num>=1000){
            ret += get_multi_str('M',num/1000);
            num = num - (num/1000)*1000;
        }
        return ret + intToRoman_1000(num);
    }
};