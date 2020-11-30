class Position:

    def __init__(self, seeds_value):
        self.cells_player = [(i * 2) for i in range(seeds_value)]
        self.cells_computer = [(i*2 + 1) for i in range(seeds_value)]
        self.computer_play = False
        self.seeds_player = seeds_value
        self.seeds_computer = seeds_value

    def get_computer_seed(self):
        return self.seeds_computer

    def get_player_seeds(self):
        return self.seeds_player

    def play_move(self, bot, indice):
        if bot:
            seeds = self.cells_computer[indice]
        else:
            seeds = self.cells_player[indice]
        i = indice + 1
        while seeds != 0:
            if i < 12:
                self.cells_computer

    def __repr__(self):
        return f"Etat plateau joueur: {self.cells_player}\nEtat plateau CPU: {self.cells_computer}\n"

test = Position(12)
print(test)