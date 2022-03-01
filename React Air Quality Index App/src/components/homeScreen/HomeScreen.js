import React from 'react';
import styles from './HomeScreen.module.css';
import Warning from './Warning';
const HomeScreen = (props)=>{
    return(
        <div className={styles['home-screen']}>
            {!props.isNameValid?<Warning/>:""}
            <h1>Air IQ  <i class="fas fa-fan"></i></h1>
            <form onSubmit={props.cityNameHandler}>
                <input type="text" placeholder="Enter A City Name"></input>
                <button type="submit"><i class="fas fa-search"></i></button>
            </form>

        </div>
    );
}

export default HomeScreen;