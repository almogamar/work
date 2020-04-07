
def home_screen():
	"""this function will print the home screen"""
	
	print(""" 	  _    _                                         
	 | |  | |                                        
	 | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  
	 |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
	 | |  | | (_| | | | | (_| | | | | | | (_| | | | |
	 |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
			      __/ |                      
			     |___/""")
	print(6)				 
	return 6
	

def choose_word(file_path, index):
	
	"""this function will find me the amunt of worss in the file and the word in the given index 
	:parm file_path: the file dir thet contain the words
	:parm index: the index of the word i want 
	:type file_path: str
	:type index: int"""
	
	
	length = []
	total = []
	
	file_input  = open(file_path, 'r')
	
	string = file_input.readline()
	comp = list(string.split(' '))
	
	for i in comp:
		
		total.append(i)
		
		if i not in length:
				
			length.append(i)
			
				
	amunt = len(length)
	
	
	
	item = total[(index % len(total)) - 1]	
	
	return item 

def show_hidden_word(secret_word, old_letters_guessed):
	"""this function will convert and show me the progrese i did gessing 
	:parm secret_word: the word i need to guess
	:parm old_letters_guessed: the letters i already guessed
	:type secret_word: str
	:type old_letters_guessed: list
	:return: the new str
	:rtype: str"""
	
	new = secret_word.replace(secret_word, '_ ' * len(secret_word))
	
	new_list = list(new)
	
	for item in range(len(secret_word)):
		
		
		for letter in range(len(old_letters_guessed)):
			
			
			if secret_word[item] == old_letters_guessed[letter]:
				
				new_list[item * 2] = old_letters_guessed[letter]
				
		
		
	temp = ''
	new = temp.join(new_list[:-1])
	
	
	return new


def print_hangman(num_of_tries):
	"""this function will print the stat of the player in the game a cording to his input
	:parm num_of_tries: the amount of losing points
	:type num_of_tries: int 
	:return: none
	:rtype: none """


	hangman = {1: """
    x-------x""", 2: """
    x-------x
    |
    |
    |
    |
    |""", 3: """
    x-------x
    |       |
    |       0
    |
    |
    |""", 4: """
    x-------x
    |       |
    |       0
    |       |
    |
    |""", 5: """
    x-------x
    |       |
    |       0
    |      /|\ 
    |
    |""", 6: """
    x-------x
    |       |
    |       0
    |      /|\ 
    |      /
    |""", 7: """
    x-------x
    |       |
    |       0
    |      /|\ 
    |      / \ 
    |"""}
	
	print(hangman[num_of_tries])


def check(letter_guessed):
	"""this functoin will print the already guessed letters
	:parm letter_guessed: this is the list of letters that been guessed
	:type letter_guessed: list
	:return: non
	:rtype: none"""
	
	str_letters = " -> "
	print("X")
	print(str_letters.join(letter_guessed))

def try_update_letter_guessed(letter_guessed, old_letters_guessed, secret_word):
	"""this function will find if the input is vaid and return the result.
	:parm letter: this is the letter the user inputed
	:parm old_letters_guessed: the list i will compere the input to to check if it is valid
	:parm secret_word: the word the player need to guess
	:type letter: str
	:type old_letters_guessed: list of str
	:type secret_word: str
	:return: if the input is vaild or not 
	:rtype: bool
	"""
	
	letter_fixed = letter_guessed.lower()
	
	abc_check = 'abcdefghijklmnopqrstuvwxyz'
	
	old_letters_guessed.sort()
	
	if(letter_fixed in old_letters_guessed ):
		
		check(old_letters_guessed)
		return True

	elif(len(letter_fixed) > 1):
		
		check(old_letters_guessed)
		return True
		
	elif(letter_fixed not in abc_check):

		check(old_letters_guessed)
		return True
	
	elif(letter_fixed == ''):
		
		check(old_letters_guessed)
		return True
	
	elif(letter_fixed not in secret_word):
		
		old_letters_guessed.append(letter_fixed)
		print(':(')
		return False
	
	else:
		
		old_letters_guessed.append(letter_fixed)
		return True


def check_win(secret_word, old_letters_guessed):
	"""this function will convert and show me the progrese i did gessing 
	:parm secret_word: the word i need to guess
	:parm old_letters_guessed: the letters i already guessed
	:type secret_word: str
	:type old_letters_guessed: list
	:return: the new str
	:rtype: str"""
	
	new = secret_word.replace(secret_word, '_ ' * len(secret_word))
	
	new_list = list(new)
	
	for item in range(len(secret_word)):
		
		
		for letter in range(len(old_letters_guessed)):
			
			
			if secret_word[item] == old_letters_guessed[letter]:
				
				new_list[item * 2] = old_letters_guessed[letter]
				
		
		
	temp = ''
	new = temp.join(new_list[:-1])
	
	if '_' in new:
		return False
	
	else:
		return True


def main():

	num_of_tries = 1
	old_letters_guessed = []
	stat = False
	
	MAX_TRIES = home_screen()
	
	file_dir = input("Enter file path: ")
	index = int(input("Enter index: "))
	
	secret_word = choose_word(file_dir, index)
	
	print("\n\tlet's start")
	
	for i in range(MAX_TRIES):
		
		print_hangman(num_of_tries)
		
		print(show_hidden_word(secret_word,old_letters_guessed))
		
		guess = input("Guess a letter: ")
		
		while try_update_letter_guessed(guess, old_letters_guessed , secret_word):
			
			print(show_hidden_word(secret_word,old_letters_guessed))
			
			if check_win(secret_word, old_letters_guessed):
				
				stat = True
				break
			
			guess = input("Guess a letter: ")
		
		if stat:
			break
			
		num_of_tries += 1
		
	if stat:
	
		print("YOU WIN!!!!")
	
	else:
		
		print_hangman(num_of_tries)
		print(show_hidden_word(secret_word,old_letters_guessed))
		
		print('YOU LOSE')
	
if __name__ == "__main__":

	main()

