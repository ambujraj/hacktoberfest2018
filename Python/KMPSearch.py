# This is my favourite code snippet because it provides an effective way of searching

from timeit import default_timer as timer

def KMPSearch(pat, txt): 

    start = timer()
    result_list = []
    M = len(pat) 
    N = len(txt) 
  
    #lps : Longest Prefix Suffix  
    lps = [0] * M 
    j = 0 
   
    computeLPSArray(pat, M, lps) 
  
    i = 0
    while i < N: 

        if pat[j] == txt[i]: 
            i += 1
            j += 1
  
        if j == M: 
            
            result_list.append(str(i-j))
            j = lps[j-1] 
  
        # mismatch after j matches 
        elif i < N and pat[j] != txt[i]: 
            if j != 0: 
                j = lps[j-1] 
            else: 
                i += 1
    end = timer()
    tme = end-start
    time_of_running = "%.8f"%tme

    return time_of_running, result_list
     
def computeLPSArray(pat, M, lps): 
    len = 0 # Length of the previous longest prefix suffix 
    lps[0] # lps[0] is always 0 
    i = 1
  
    # The loop calculates lps[i] for i = 1 to M-1 
    while i < M: 
        if pat[i]== pat[len]: 
            len += 1
            lps[i] = len
            i += 1
        else: 
            if len != 0: 
                len = lps[len-1] 
            else: 
                lps[i] = 0
                i += 1


def main():

    # Searching for python position in inner text.
    time_of_running, result_list = KMPSearch("python","python is best! python! python! python!")
    print('Running time: {}, results: {}'.format(time_of_running, result_list))
    # Output-> Running time: 0.00001061, results: ['0', '16', '24', '32']




if __name__ == "__main__":
        main()