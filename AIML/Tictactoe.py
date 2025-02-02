#tic tac toe problem
#'X' will try to maximize its win chances and will try to minimize 'O's win chances
l = [] #coordinates to place X
def tictactoe(board, turn, flag):
    #lets not keep a base case
    #base case will lead to early returns, not what we want
    global l
    minimum = 100000
    maximum = 0
    count = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == '.':
                #I CAN PLACE HERE
                if turn == 0:
                    #CHECK WHETHER 'X' HAS WON OR NOT
                    board[i][j] = 'X'
                    if (hasWon(board, 'X')):
                        count = 1 + tictactoe(board, 1 - turn, 1)
                    else:
                        count = tictactoe(board, 1 - turn, 1)
                else:
                    board[i][j] = 'O'
                    if (hasWon(board, 'O')):
                        count = 1 + tictactoe(board, 1 - turn, 1)
                    else:
                        count = tictactoe(board, 1 - turn, 1)
                board[i][j] = '.'
                #NOW LOOK AT THE COUNT AND SEE IF IT IS GREATER THAN MAX
                if turn == 0:
                    if count > maximum:
                        maximum = count
                        if flag == 0:
                            l = [i, j]
                else:
                    #minimize this
                    minimum = min(count, minimum)
    if turn == 1:
        if minimum == 100000:
            return 0
        return minimum
    return maximum
                    
                    

def hasWon(board, turn):
    #check whether rows of turn are complete
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] == turn:
            return True;
    for i in range(3):
        if board[0][i] == board[1][i] == board[2][i] == turn:
            return True;
    #check diagonal
    if board[0][0] == board[1][1] == board[2][2] == turn:
        return True
    if board[0][2] == board[1][1] == board[2][0] == turn:
        return True
    
#LETS RUN THE SOLVE FUNCTION TO SIMULATE THE GAME
def simulateTheGame():
    turn = 0
    board = [['.', '.', '.'], ['.', '.', '.'], ['.', '.', '.']]
    
    while True:
        # place according to turn
        if turn == 0:
            tictactoe(board, 0, 0)
            # Check if l has valid coordinates before placing 'X'
            if l:  # Ensure l is not empty
                board[l[0]][l[1]] = 'X'
                printBoard(board)
                if hasWon(board, 'X'):
                    printBoard(board)  # Print the board before announcing the winner
                    print('AI HAS WON THE GAME')
                    break
            else:
                print("No valid moves available for 'X'.")
                break
            turn = 1 - turn
            
        else:
            i = input("YOUR TURN, ENTER THE COORDINATES: ")
            row = int(i.split()[0])
            col = int(i.split()[1])
            if board[row][col] == '.':
                board[row][col] = 'O'
                if hasWon(board, 'O'):
                    printBoard(board)  # Print the board before announcing the winner
                    print('YOU WON THE GAME, CONGRATULATIONS!!')
                    break
                turn = 1 - turn
            else:
                print("Invalid move. Try again.")
        
        if isDraw(board):
            print('DRAW GAME')
            break

def printBoard(board):
    for i in range(3):
        print(board[i][0] + " " + board[i][1] + " " + board[i][2])
        
def isDraw(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == '.':
                return False
    return True
