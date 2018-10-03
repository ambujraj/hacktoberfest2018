using System; 
class Pangram{ 
      
    public static bool checkPangram (string str) 
    { 
          
        // Create a hash table to mark the  
        // characters present in the string 
        // By default all the elements of  
        // mark would be false. 
        bool[] mark = new bool[26]; 
  
        int index = 0; 
  
        for (int i = 0; i < str.Length; i++) 
        { 
            // If uppercase character, subtract 'A' to find index. 
            if ('A' <= str[i] &&  
                    str[i] <= 'Z') 
                          
                index = str[i] - 'A'; 
  
                // If lowercase character,subtract 'a' to find index. 
            else if('a' <= str[i] && 
						str[i] <= 'z')
						 
                index = str[i] - 'a'; 
  
            // Marking current character as TRUE 
            mark[index] = true; 
        } 
 
        // Return false if any character is missing
        for (int i = 0; i < 26; i++) 
            if (mark[i] == false) 
                return (false); 
  
        // If all characters are present
        return (true); 
    } 
    
	//Main Function
    public static void Main()  
    { 
        string str = "The quick brown fox jumps over the lazy dog"; 
		
        if (checkPangram(str) == true) 
            Console.WriteLine(str + " is a pangram."); 
        else
            Console.WriteLine(str+ " is not a pangram."); 
  
    } 
} 
