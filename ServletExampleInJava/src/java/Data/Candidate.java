package Data;

public class Candidate {

    public Candidate(String name) {
        this.ID = NEXT_ID++;
        this.name = name;
        this.vote_count = 0;
    }   

    public int getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public int getVoteCount() {
        return vote_count;
    }

    void voteTo() {
        vote_count++;
    }
    
    private int ID;
    private String name;
    private int vote_count;
    private static int NEXT_ID = 1;
}