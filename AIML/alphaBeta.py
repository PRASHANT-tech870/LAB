def minimax(total, turn, alpha, beta):
    if total == 20:
        return 0
    elif total > 20:
        if turn:
            return -1
        else:
            return 1

    if turn:
        max_eval = -float('inf')
        for i in range(1, 4):
            eval = minimax(total + i, False, alpha, beta)
            max_eval = max(max_eval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break
        return max_eval
    else:
        min_eval = float('inf')
        for i in range(1, 4):
            eval = minimax(total + i, True, alpha, beta)
            min_eval = min(min_eval, eval)
            beta = min(beta, eval)
            if beta <= alpha:
                break
        return min_eval

total = 0

while True:
    human_move = int(input("Enter your move (1, 2, or 3): "))
    while human_move not in [1, 2, 3]:
        print("Invalid move. Please enter 1, 2, or 3.")
        human_move = int(input("Enter your move (1, 2, or 3): "))
    total += human_move
    print(f"After your move, total is {total}")
    if total >= 20:
        print("You win!")
        break

    print("AI is making its move...")
    ai_move = 1
    max_eval = -float('inf')
    for i in range(1, 4):
        eval = minimax(total + i, False, -float('inf'), float('inf'))
        if eval > max_eval:
            max_eval = eval
            ai_move = i
    total += ai_move
    print(f"AI adds {ai_move}. Total is {total}")
    if total >= 20:
        print("AI wins!")
        break
