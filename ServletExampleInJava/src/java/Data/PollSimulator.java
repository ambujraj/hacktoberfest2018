package Data;

import java.util.Random;

public class PollSimulator {

    public static void main(String[] args) {
        
        String[] candNames = new String[5];
        candNames[0] = "Deep Goyal";
        candNames[1] = "Sneha Mohan";
        candNames[2] = "Praveen Shah";
        candNames[3] = "Akshay Singh";
        candNames[4] = "Somin Majumdar";
        
        Poll poll = new Poll();
        
        poll.setCandidates( candNames );

        int nc = poll.getNumberOfCandidates();
        Random rand = new Random(55);
        for( int i = 1; i <=50; i++ ) {
            int x = 1 + rand.nextInt(nc);
            poll.vote( x );
        } 

        //Report the election result
        Candidate[] cands = poll.getCandidates();
        for(Candidate c : cands ) {
            System.out.println( c.getName() + " : " + c.getVoteCount());
        }
        System.out.println("Winner: " + poll.getWinner());
    }

}
