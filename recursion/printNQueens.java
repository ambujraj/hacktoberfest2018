package june29;

public class printNQueens {

	public static void main(String[] args) {
		boolean[][] board = new boolean[4][4];
		// printnqueensPermutations(board, 0, "");
		//printnqueensCombinations(board, 0, "", 0);

		// long start = System.currentTimeMillis();
		// printnqueensReactive(board, 0, "", 0);
		// long end = System.currentTimeMillis();
		// System.out.println(end - start);
		//
		// long start = System.currentTimeMillis();
		 printnqueensProactive(board, 0, "", 0);
		// long end = System.currentTimeMillis();
		// System.out.println(end - start);

		//printnqueensSubsequence(board, 0, 1, "");
		//printnKnightsProactive(board, 0, "", 0);
	}

	static int counter = 0;

	private static void printnKnightsProactive(boolean[][] board, int kpsf, String csf, int lkpcell) {

		if (kpsf == board.length) {
			counter++;
			System.out.println(counter + ". " + csf);
			return;
		}

		for (int i = lkpcell + 1; i <= board.length * board.length; i++) {
			int ir = (i - 1) / board.length;
			int ic = (i - 1) % board.length;

			if (board[ir][ic] == false) {
				if (isKnightSafe(board, ir, ic)){
					board[ir][ic] = true;
					printnKnightsProactive(board, kpsf + 1, csf + "k" + (kpsf + 1) + "c" + i + " ", i);
					board[ir][ic] = false;
				}
			}
		}

	}
	
	private static void printnqueensPermutations(boolean[][] board, int qpsf, String csf) {

		if (qpsf == board.length) {
			counter++;
			System.out.println(counter + ". " + csf);
			return;
		}

		for (int i = 1; i <= (board.length * board.length); i++) {
			int ir = (i - 1) / board.length;
			int ic = (i - 1) % board.length;

			if (board[ir][ic] == false) {
				board[ir][ic] = true;
				printnqueensPermutations(board, qpsf + 1, csf + "q" + qpsf + "c" + i + " ");
				board[ir][ic] = false;
			}
		}

	}

	private static void printnqueensCombinations(boolean[][] board, int qpsf, String csf, int lqpcell) {

		if (qpsf == board.length) {
			counter++;
			System.out.println(counter + ". " + csf);
			return;
		}

		for (int i = lqpcell + 1; i <= board.length * board.length; i++) {
			int ir = (i - 1) / board.length;
			int ic = (i - 1) % board.length;

			if (board[ir][ic] == false) {
				board[ir][ic] = true;
				printnqueensCombinations(board, qpsf + 1, csf + "q" + qpsf + "c" + i + " ", i);
				board[ir][ic] = false;
			}
		}

	}

	private static void printnqueensReactive(boolean[][] board, int qpsf, String csf, int lqpcell) {

		if (qpsf == board.length) {
			counter++;
			if (isTheBoardSafe(board)) {
				System.out.println(counter + ". " + csf);
			}
			return;
		}

		for (int i = lqpcell + 1; i <= board.length * board.length; i++) {
			int ir = (i - 1) / board.length;
			int ic = (i - 1) % board.length;

			if (board[ir][ic] == false) {
				board[ir][ic] = true;
				printnqueensReactive(board, qpsf + 1, csf + "q" + qpsf + "c" + i + " ", i);
				board[ir][ic] = false;
			}
		}

	}

	private static void printnqueensProactive(boolean[][] board, int qpsf, String csf, int lqpcell) {

		if (qpsf == board.length) {
			counter++;
			System.out.println(counter + ". " + csf);
			return;
		}

		for (int i = lqpcell + 1; i <= board.length * board.length; i++) {
			int ir = (i - 1) / board.length;
			int ic = (i - 1) % board.length;

			if (board[ir][ic] == false) {
				if (isTheQueenSafe(board, ir, ic)) {
					board[ir][ic] = true;
					printnqueensProactive(board, qpsf + 1, csf + "q" + qpsf + "c" + i + " ", i);
					board[ir][ic] = false;
				}
			}
		}

	}

	private static void printnqueensSubsequence(boolean[][] board, int qpsf, int bno, String csf) {

		if (qpsf == board.length) {
			counter++;
			System.out.println(counter + ". " + csf);
			return;
		}

		if (bno > board.length * board.length) {
			return;
		}

		int ir = (bno - 1) / board.length;
		int ic = (bno - 1) % board.length;
		// box says no
		printnqueensSubsequence(board, qpsf, bno + 1, csf);
		if (board[ir][ic] == false) {
			if (isTheQueenSafe(board, ir, ic)) {
				board[ir][ic] = true;
				// box says yes
				printnqueensSubsequence(board, qpsf + 1, bno + 1, (csf + "q" + qpsf + "b" + bno + ""));
				board[ir][ic] = false;
			}
		}

	}

	private static boolean isTheBoardSafe(boolean[][] board) {

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == true) {
					if (isTheQueenSafe(board, i, j) == false) {
						return false;
					}
				}
			}
		}

		return true;
	}

	private static boolean isTheQueenSafe(boolean[][] board, int r, int c) {

		int[][] dirs = { { -1, 0 }, // north
				{ -1, 1 }, // north-east
				{ 0, 1 }, // east
				{ 1, 1 }, // south-east
				{ 1, 0 }, // south
				{ 1, -1 }, // south-west
				{ 0, -1 }, // west
				{ -1, -1 } // north-west
		};

		for (int rad = 1; rad < board.length; rad++) {
			for (int dir = 0; dir < 8; dir++) {
				int renemy = r + (dirs[dir][0] * rad);
				int cenemy = c + (dirs[dir][1] * rad);
				if (renemy >= 0 && renemy < board.length && cenemy >= 0 && cenemy < board[0].length
						&& board[renemy][cenemy] == true) {
					return false;
				}
			}
		}

		return true;

	}
	
	
	private static boolean isKnightSafe(boolean[][] board, int r, int c){
		
		int[][] dirs = {
				{-2, 1},
				{-1, 2},
				{1, 2},
				{2, 1},
				{2, -1},
				{1, -2},
				{-1, -2},
				{-2, -1}
		};
		
		for(int dir=0; dir<8; dir++){
			int renemy = r + dirs[dir][0];
			int cenemy = c + dirs[dir][1];
			if (renemy >= 0 && renemy < board.length && cenemy >= 0 && cenemy < board[0].length
					&& board[renemy][cenemy] == true) {
				return false;
			}
		}
		
		return true;
 	}

}
