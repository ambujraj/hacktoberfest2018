from chatterbot.trainers import ListTrainer
#from chatterbot import ChatBot #importando o chatbot

#bot = ChatBot('Teste') # create chatbot

conv = [
"Ei"
"Olá"
"Qual é seu nome?"
"Meu nome é Aurial"
"Como vai você?"
"Eu estou em desenvolvimento, porém bem"
"Isso é bom"
"Obrigado, seja bem vindo"
]

trainer = ListTrainer(chatbot)

trainer.train(conv)

response = chatbot.get_response("Bom dia!")
print(response)
