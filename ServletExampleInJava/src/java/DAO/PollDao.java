package DAO;

import Data.Candidate;
import Data.Poll;

public class PollDao {

    public static Poll poll;

    public PollDao() {

        if (poll == null) {
            poll = new Poll();
        }
    }

    public Candidate[] setCandidates(String candidate[]) {
        poll = new Poll();
        poll.setCandidates(candidate);
        return poll.getCandidates();
    }

    public boolean vote(int id) {
        try {
            poll.vote(id);
        } catch (Exception E) {
            return false;
        }
        return true;
    }

    public Candidate[] getSummary() {
        return poll.getCandidates();
    }

    public String winner() {
        return "Winner is : " + poll.getWinner();
    }
}
