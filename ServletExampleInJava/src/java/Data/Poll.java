package Data;

import java.util.HashMap;

public class Poll {

    public void vote(int candidate_id) {
        Candidate c = candidates.get(candidate_id);
        c.voteTo();
        candidates.put(candidate_id, c);
    }

    public void setCandidates( String [] names ) {

        Candidate c;
        for (String cname : names ) {
            c = new Candidate( cname );
            candidates.put(c.getID(), c);
        }        
    }
    
    public int getNumberOfCandidates() {
        return candidates.size();
    }
    
    public String getWinner() {  
        
        String winner_candidate;

        Candidate[] cands = getCandidates();
        int wc = -1, max_vote = -1;
        for(Candidate c : cands ) {
            if ( c.getVoteCount() > max_vote )
            {
                wc = c.getID();
                max_vote = c.getVoteCount();
            }
        }
        winner_candidate = candidates.get(wc).getName();           
        return winner_candidate;

    }        
    
    public Candidate[] getCandidates() {
        Candidate[] cands = new Candidate[candidates.size()];
        int i = 0;
        for (HashMap.Entry<Integer,Candidate> c : candidates.entrySet()) 
            cands[i++] = c.getValue();
        return cands;
    }   
    private final HashMap<Integer, Candidate> candidates = new HashMap<>();
    
}
