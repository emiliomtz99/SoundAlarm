import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from playsound import playsound
import time

starttime = time.time()

# Fetch the service account key JSON file contents
cred = credentials.Certificate('downloadThisFileFrom.json') 
# https://console.firebase.google.com/u/0/project/PROYECT NAME/settings/serviceaccounts/adminsdk -> Generate new private key

# Initialize the app with a custom auth variable, limiting the server's access
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://firebaseName.firebaseio.com',    
})

# The app only has access as defined in the Security Rules


def Alguien():
	if ref.get() == 666:		
		playsound("Alarm.mp3")
		ref.set(0)
		
		
while True:
	ref = db.reference('/Alarm')	
	Alguien()
	time.sleep(.75)
