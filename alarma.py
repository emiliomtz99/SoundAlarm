import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from playsound import playsound
import time

starttime = time.time()

# Fetch the service account key JSON file contents
cred = credentials.Certificate('haboots-86f0b-firebase-adminsdk-kxjz1-771d99108a.json')

# Initialize the app with a custom auth variable, limiting the server's access
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://haboots-86f0b.firebaseio.com',    
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