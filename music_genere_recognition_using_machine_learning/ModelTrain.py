import numpy
import pandas
import joblib

from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.svm import SVC
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier


def main():
    print("Training the model...")
    data_set=pandas.read_csv('data_set.csv',index_col=False)
    data_set=numpy.array(data_set)
    print("Dataset shape:",data_set.shape)
    number_of_rows,number_of_cols=data_set.shape
    data_x=data_set[:,:number_of_cols-1]
    data_y=data_set[:,number_of_cols-1]
    x_train,x_test,y_train,y_test=train_test_split(data_x,data_y,test_size=0.2)
	
    print("Training the model...")
    model=SVC(C=100, gamma=0.08)
    model.fit(x_train,y_train)
    print(model.score(x_test,y_test))
	
    
    joblib.dump(model,'model.pkl')
    print("Trained and saved the model to project folder successfully")
    
if __name__=="__main__":
    main()