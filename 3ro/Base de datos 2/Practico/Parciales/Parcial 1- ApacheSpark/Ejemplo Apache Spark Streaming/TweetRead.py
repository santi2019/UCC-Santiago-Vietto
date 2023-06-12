import tweepy #Paquete de python para trabajar con twitter
from tweepy import OAuthHandler 
from tweepy import Stream
from tweepy.streaming import StreamListener
import socket #Protocolo de control de transmisión. 
import json 


# Claves y tokens de acceso. 
consumer_key    = 'T5inRDfXTR1qEOanULBS2tonH'
consumer_secret = '04vQ9jeWLhqOzamMIA7Dvu4I5ZVt1Z4fC6kxrMGHARxUeqDMFA'
access_token    = '1440308967498928136-7N6xw9EXxYgreg5D4YNurMy5jMyvEw'
access_secret   = 'ea0RpHSAVYoztdZMCgNZ0JeZSTIMpkqnLRUzFWYRmzCe9'


class TweetsListener(StreamListener):

  def __init__(self, csocket):
      self.client_socket = csocket

  def on_data(self, data):
      try:
          msg = json.loads( data )
          print(msg['text'].encode('utf-8')) #Se codifica en utf-8 por los emojis. Nos evitamos un error y los emojis se muestran como un espacio en blanco.
          self.client_socket.send((str(msg['text'])).encode('utf-8'))
          return True
      except BaseException as e:
          print("Error on_data: %s" % str(e))
      return True

  def on_error(self, status):
      print(status)
      return True

def sendData(c_socket):
  auth = OAuthHandler(consumer_key, consumer_secret)
  auth.set_access_token(access_token, access_secret)

  twitter_stream = Stream(auth, TweetsListener(c_socket))
  twitter_stream.filter(track=['football']) #Cualquier cadena que pongamos debe estar en el tweet para que aparezca en la transmisión.

if __name__ == "__main__":
  s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)         # Se crea un objeto socket 
  host = "127.0.0.1"     
  port = 5557                 # Se reserva el puerto para su uso 
  s.bind((host, port))        # Ligamos el host con el puerto

  print("Listening on port: %s" % str(port))

  s.listen(5)                 # Espera la conexión con el cliente 
  c, addr = s.accept()        # Establecer conexión con el cliente

  print("Received request from: " + str(addr))

  sendData(c)
