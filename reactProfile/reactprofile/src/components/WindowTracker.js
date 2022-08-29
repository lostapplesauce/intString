import React from 'react';
import '../stylesheets/WindowTracker.css'

export default function WindowTracker() {
    const [windowWidth, setWindowWidth] = React.useState(window.innerWidth);
    const [windowHeight, setWindowHeight] = React.useState(window.innerHeight);

    React.useEffect(() => {
        function watchWidth() {
            setWindowWidth(window.innerWidth);
        }
        window.addEventListener("resize", watchWidth);

        return function(){ window.removeEventListener("resize", watchWidth)}
    }, []);

    React.useEffect(() => {
        function watchHeight() {
            setWindowHeight(window.innerHeight);
        }
        window.addEventListener("resize", watchHeight);

        return function(){ 
            window.removeEventListener("resize", watchHeight)
        }
    }, []);
    
    return (
        <div className="windowTracker">
        <h2 className="windowTracker--title">Window size tracking:</h2>
        <h3 className="windowTracker--width">Window width: {windowWidth} </h3>
        <h3 className="windowTracker--height">Window height: {windowHeight} </h3>
      </div>
    );
    
}