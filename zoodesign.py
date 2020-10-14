class Animals:
    """ Can be placed inside cages, and according to its place in food chain
    it has a list attribute of its prey (what it likes to eat).
    """

    prey = []

    def __init__(self):
        self.name = 'Unnamed'       # Default naming, to be modified

    def __repr__(self):
        """ Identifies the Animals by its name and species (subclass).
        """
        species = self.__class__.__name__
        return self.name + " " + species if self.name != 'Unnamed' else species


class Goat(Animals):

    def __init__(self):
        super().__init__()


class Mouse(Animals):

    def __init__(self):
        super().__init__()


class Jackal(Animals):

    prey = [Goat, Rabbit]      # Animals subclasses that Jackals eat

    def __init__(self):
        super().__init__()


class Rabbit(Animals):

    prey = [Mouse]     # Animals subclasses that Rabbits eat

    def __init__(self):
        super().__init__()



class Owl(Animals):

    prey = [Mouse]     # Animals subclasses that Owls eat

    def __init__(self):
        super().__init__()



class Kite(Animals):

    prey = [Snake]     # Animals subclasses that Kites eat

    def __init__(self):
        super().__init__()


class WildCat(Animals):

    prey = [Rabbit, Mouse]     # Animals subclasses that WildCats eat

    def __init__(self):
        super().__init__()


class Snake(Animals):

    prey = [Mouse]     # Animals subclasses that Snakes eat

    def __init__(self):
        super().__init__()




class Lion(Animals):

    prey = [Goat, Jackal, WildCat, Kite]
    # Animals subclasses that Lions eat

    def __init__(self):
        super().__init__()


class Cage:
    """ Contains a list of Animalss inside and performs methods to check
    intern competition where there might be a conflict of prey and predator,
    where a prey gets eaten.
    """

    def __init__(self):
        self.Animalss_list = []
        self.name = 'Cage'      # Default name configuration

    def __repr__(self):
        if len(self.Animalss_list) > 0:      # Checks if cage isn't empty
            return "{} contains {} Animals(s): {}".format(
                self.name, self.n_of_Animalss(),
                ', '.join(map(str, self.Animalss_list)))
        else:
            return "{} (empty)".format(self.name)

    def n_of_Animalss(self):
        return len(self.Animalss_list)

    def check_prey(self):
        """ Method for checking the Animalss chain food competition inside a
        cage: iterates through its Animalss list and kills (deletes) the
        predator's prey.
        """
        death_statements = {}       # Dictionary to handle preys getting eaten
        # Check if any Animalss in the list have listed prey inside this cage:
        for predator in self.Animalss_list:
            for prey in self.Animalss_list:      # Parses Animalss prey's lists
                """ Compares the listed classes in an Animals's prey list
                with the class of each other Animals on the cage. """
                if type(prey) in predator.prey:
                    death_statements[prey] = (prey, "{} got eaten by {}."
                                              .format(prey, predator))
        if len(death_statements) > 0:       # Checks if there were any deaths
            print("Oops! Seems like you put predator and prey on same cage.")
            for prey in death_statements:
                print(death_statements[prey][1])        # Prints name of prey
                self.Animalss_list.remove(death_statements[prey][0])
                # Prints statement of death identifying the predator
        print('Now ' + str(self))       # Shows updated list of Animalss in cage

    def add_Animalss(self, add_list):
        """ Inserts Animalss inside the Cage object. """
        duplicate_Animalss = []
        for Animals in add_list:
            """ Checks if the parent class of the list item is not an Animals
            object (in this case, the item won't be inserted in the Cage)
            """
            if Animals.__class__.__base__ != Animals:
                print("{} object could not be added because it's not an "
                      "Animals subclass.".format(Animals.__class__.__name__))
            elif Animals not in self.Animalss_list:
                self.Animalss_list.append(Animals)
                # Inserts Animals object in cage if not already inside
            elif Animals not in duplicate_Animalss:
                    duplicate_Animalss.append(Animals)
        if len(duplicate_Animalss) > 0:      # Checks duplicate insert attempt
            print("Duplicate Animals(s) found: {} already inside.".format(
                ', '.join(map(str, duplicate_Animalss))))
            print(self)
        return self.check_prey()
        # Starts check on whether there is prey and predator on the same cage


class Zoo:
    """ Contains a list of Cage objects and informs about the Animalss inside
    itself.
    """

    def __init__(self):
        super().__init__()
        self.name = 'Zoo'       # Default name
        self.cages = []

    def __repr__(self):
        if len(self.cages) > 0:
            return '{} contains {} cage(s) and a total of {} Animals(s)'.format(
                self.name, len(self.cages), self.n_of_Animalss())
        else:
            return '{} (empty)'.format(self.name)

    def add_cages(self, list_to_add):       # Takes list of cages as argument
        for cage in list_to_add:
            if type(cage) == Cage:
                self.cages.append(cage)
            else:
                print("{} object could not be added because it's not a Cage."
                      .format(cage.__class__.__name__))
        return self

    def n_of_cages(self):       # User method to find out number of cages
        return len(self.cages)

    def n_of_Animalss(self):
        """ Accessing attributes from instances of class Cage, it calculates
        how many Animalss are in total inside all cages of the zoo.
        """
        self.n_of_Animalss = 0
        for item in self.cages:
            # Appends to attribute sum of Animalss inside each cage
            self.n_of_Animalss += len(item.Animalss_list)
        return self.n_of_Animalss
