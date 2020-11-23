class Position:

    def __init__(self, seeds_value):
        self.cells_player = [4 for _ in range(seeds_value)]
        self.cells_computer = [4 for _ in range(seeds_value)]
        self.computer_play = False
        self.seeds_player = seeds_value
        self.seeds_computer = seeds_value

    def get_computer_seed(self):
        return self.seeds_computer

    def get_player_seeds(self):
        return self.seeds_player

    def __repr__(self):
        return f"Etat plateau joueur: {self.cells_player}\nEtat plateau CPU: {self.cells_computer}\n"

test = Position(12)
print(test)