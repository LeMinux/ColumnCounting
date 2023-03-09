package cpsc2150.extendedConnectX.models;

/*
 *Initalization ensures:
 * A game board with a size of MAX_ROWS x MAX_COLS
 * that needs NUM_TO_WIN tokens in a row to win
 *
 * @constraints
 * rows = MAX_ROWS
 * columns = MAX_COLS
 * tokens needed to win = NUM_TO_WIN
 */
public interface IGameBoard{

	public final int MAX_ROWS = 9;
	public final int MAX_COLS = 7;
	public final int NUM_TO_WIN = 5;

	/**
	* gets the the number of rows from self
	*
	*@return the number of rows self has
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*/
	public int getNumRows();

	/**
	* gets the the number of columsn from self
	*
	*@return the number of columns self has
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*/
	public int getNumColumns();

	/**
	* returns how many tokens are needed for a win
	*
	*@return how many tokens are need in a row to win.
		    this can be vertically, horizontally, or diagonally
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*/
	public int getNumToWin();

	/**
	* Checks if column of self is free for another token
	*
	*@param col The column to check if free
	*
	*@return true if it can fit another token false if it can not fit
	*	    another token
	*
	*@pre
	*	0 {@code <=} col {@code <} MAX_COLS
	*
	*@post
	*	[upper most row of self is empty]
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*/
	public default boolean checkIfFree(int col){
		BoardPosition top = new BoardPosition(MAX_ROWS - 1, col);
		return (whatsAtPos(top) == ' ');
	}


	/**
	* Places the token in the lowest row possible for that column
	*
	*@param player character representing the player
	*@param col column to place the player token in
	*
	*@pre
	*	checkIfFree() = true AND
	*	player = 'X' OR player = 'O' AND
	*	0 {@code <=} col {@code <} MAX_COLS
	* 
	*@post
	*	[lowest row of self] = player
	*/
	public void placeToken(char player, int col);

	/**
	* Checks if the last token placed in a column results in a
	* win.
	*
	*@param lastPlayed column of last played token
	*
	*@return true if result is a win of NUM_TO_WIN tokens false otherwise.
	*
	*@pre
	*	0 {@code <=} lastPlayed {@code <} MAX_COLS AND
	*	[lastPlayed is last played column]
	*
	*@post
	*	board = #board
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	checkForWin() iff [last played token results in a win]
	*/
	public default boolean checkForWin(int lastPlayed){
		BoardPosition checkCell = new BoardPosition(MAX_ROWS - 1, lastPlayed);
		while(whatsAtPos(checkCell) == ' '){
			checkCell = new BoardPosition(MAX_ROWS - 1, --lastPlayed);
		}
		char player = whatsAtPos(checkCell);

		return(checkHorizWin(checkCell,player) || checkVertWin(checkCell,player) || checkDiagWin(checkCell,player));
	}

	/**
	* Checks to see if the game has resulted in a tie aka there are no free
	* positions left
	*
	*@return True if all rows are occupied false otherwise
	*
	*@pre
	*	checkforWin() = false AND
	*	checkDiagWin() = false AND
	*	checkVertWin() = false AND
	*	checkHorizWin() = false
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	checkTie() iff [top row of self is full]
	*/
	public default boolean checkTie(){
		for(int c = 0; c < MAX_COLS; ++c){
			if(checkIfFree(c) == true){
				return false;
			}
		}
		return true;
	}

	/**
	* Checks to see if the last token results in a victory of 5 in a row
	* horizontally
	*
	*@param cell Specific position of the board to check first
	*@param player The player token to check for
	*
	*@return True if a horizontal win of NUM_TO_WIN tokens false otherwise
	*
	*@pre
	*	player = 'X' OR player = 'O' AND
	*	[cell is the last played cell]
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	checkHorizWin iff [NUM_TO_WIN tokens of player in a row horizontally]
	*/
	public default boolean checkHorizWin(BoardPosition cell, char player){
		//do{

		//}while();
		return false;
	}

	/**
	* Checks to see if the last token results in a victory of 5 in a row
	* vertically
	*
	*@param cell Specific position of the board to check first
	*@param player The player token to check for
	*
	*@return True if a vertical win of NUM_TO_WIN tokens false otherwise
	*
	*@pre
	*	player = 'X' OR player = 'O' AND
	*	[cell is the position of the last played token]
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	checkVertWin() iff [NUM_TO_WIN tokens of player in a row vertically]
	*/
	public default boolean checkVertWin(BoardPosition cell, char player){
		//do{

		//}while();
		return false;
	}

	/**
	* Checks to see if the last token results in a victory of 5 in a row
	* diagonally
	*
	*@param cell Specific position of the board to check first
	*@param player The player token to check for
	*
	*@return True if a diagonal win of NUM_TO_WIN tokens false otherwise
	*
	*@pre
	*	player = 'X' OR player = 'O' AND
	*	[cell is the position of the last played token]
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	checkDiagWin() iff [NUM_TO_WIN tokens of player in a row diagonally]
	*/
	public default boolean checkDiagWin(BoardPosition cell, char player){
		//do{

		//}while();
		return false;
	}

	/**
	* Returns what player is at the specified position
	*
	*@param cell Specific position of the board to check for
	*
	*@return player token 'X' or player token 'O' or '' if empty
	*
	*@pre
	*	[cell is valid position of self]
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	(whatsAtPos() = 'X' iff [player in cell is 'X']) OR
	*	(whatsAtPos() = 'Y' iff [player in cell is 'Y']) OR
	*	(whatsAtPos() = '' iff [player in cell is ''])
	*/
	public char whatsAtPos(BoardPosition cell);

	/**
	* returns if a player is at the specified position
	*
	*@param cell The specified cell to check
	*
	*@return True if a player token is at the position false otherwise
	*
	*@pre
	*	player = 'X' OR player = 'O'
	*	[cell is a valid position on self]
	*
	*@post
	*	|self| = #self
	*	[rows of self] = #[rows of self]
	*	[columns of self] = #[columns of self]
	*	isPlayerAtPos() iff [player in the specified cell]
	*/
	public boolean isPlayerAtPos(BoardPosition cell, char player);
}
