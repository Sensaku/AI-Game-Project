class Position:

    def __init__(self, seeds_value):
        self.cells_player = [4 for i in range(seeds_value)]
        self.cells_computer = [4 for i in range(seeds_value)]
        self.computer_play = False
        self.seeds_player = seeds_value
        self.seeds_computer = seeds_value

    def get_computer_seed(self):
        return self.seeds_computer

    def get_player_seeds(self):
        return self.seeds_player

    def illegal_moove(self,bot, indice):
        if bot:
            if self.cells_computer[indice] == 0:
                raise ValueError("Case vide")
        else:
            if self.cells_player[indice] == 0:
                raise ValueError("Case vide")

    def play_move(self, bot, indice):
        try:
            game.illegal_moove(game.computer_play, indice)
        except ValueError:
            print("Case vide!")
            exit(-1)

        if bot:
            seeds = self.cells_computer[-(indice + 1)]
            self.cells_computer[-(indice + 1)] = 0
        else:
            seeds = self.cells_player[indice]
            self.cells_player[indice] = 0

        if bot:
            i = indice + 12 + 1
        else:
            i = indice + 1

        while seeds != 0:
            if i < 12 or i > 24:
                self.cells_player[i] += 1
                seeds -= 1
            else:
                self.cells_computer[- (i - 11)] += 1
                seeds -= 1
            i = (i + 1) % 24

    def __repr__(self):
        return f"Etat plateau joueur: {self.cells_player}\nEtat plateau CPU: {self.cells_computer}\n"


game = Position(12)
while sum(game.cells_player) + sum(game.cells_computer) > 8:
    take = int(input("Quel case?\n"))
    if not game.computer_play:
        game.play_move(game.computer_play, take)
        game.computer_play = True
    else:
        game.play_move(game.computer_play, take)
        game.computer_play = False

    print(game)

