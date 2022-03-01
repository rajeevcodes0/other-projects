import React from 'react';
import styles from './CityInfo.module.css';

const CityInfo = (props) => {
    console.log(props.children);
    const data = props.data;
    //data is an object and within it we have an array named 'data', this array contains an object
    // which contains all the aqi info.
    const aqi = data.data[0].aqi;

    let comment="";
    let color;

    if(aqi>0 && aqi<=50){
        comment="Good";
        color="green";
    }else if(aqi>50 && aqi<=100){
        comment = "Moderate";
        color="yellow";
    }else if(aqi>100 && aqi<=150){
        comment = "Unhealthy For Sensitive Groups";
        color="orange";
    }else if(aqi>150 && aqi<=200){
        comment = "Unhealthy";
        color="red";
    }else if(aqi>200 && aqi<=250){
        comment = "Very Unhealthy";
        color="purple";
    }else{
        comment="Hazardous";
        color="maroon";
    }
    return(
        <div className={styles['city-info']}>
            <h1>Air IQ</h1>
            <p>{`${data.city_name},${data.country_code}`}</p>
            <p>Air Quality Index: {`${aqi}`}</p>
            <p><i class="fas fa-circle" style={{color:`${color}`}}></i>  This AQI is {comment}</p>
            <button onClick={props.onBack}>BACK</button>

        </div>
    );
}

export default CityInfo;