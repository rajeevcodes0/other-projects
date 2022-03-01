import React,{useState} from "react";

import HomeScreen from './homeScreen/HomeScreen';
import CityInfo from './cityInfo/CityInfo';

import styles from './Container.module.css';

const Container = () => {
    const [data, setData] = useState({});
    const [cityName, setCityName] = useState("");
    const [isNameValid,setIsNameValid] = useState(true);

    const cityNameHandler = (e) =>{    
        e.preventDefault();
        //creating the request object and making API call
        const request = new XMLHttpRequest();

        request.addEventListener("readystatechange",()=>{
          if(request.readyState===4 && request.status===200){
            setData(JSON.parse(request.responseText));
            setCityName(e.target[0].value)
            setIsNameValid(true);
          }
          else if(request.readyState===4 && request.status!==200){
            setIsNameValid(false);
          }
        })
        request.open("GET",`https://api.weatherbit.io/v2.0/current/airquality?city=${e.target[0].value}&key=02d24335c3704059a69d9f22faf97a92`)
        request.send();
    }

    const onBackHandler = ()=>{
      setCityName("")
    }
  return (
    <div className={styles.container}>
      {cityName?<CityInfo data={data} onBack={onBackHandler}/>:<HomeScreen cityNameHandler={cityNameHandler} isNameValid={isNameValid}/>}
      
     
    </div>
  );
};

export default Container;
