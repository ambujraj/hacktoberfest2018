$(document).ready(() => {
  $.fn.extend({
    animateCss: function (animationName, callback) {
      var animationEnd = (function (el) {
        var animations = {
          animation: 'animationend',
          OAnimation: 'oAnimationEnd',
          MozAnimation: 'mozAnimationEnd',
          WebkitAnimation: 'webkitAnimationEnd',
        };

        for (var t in animations) {
          if (el.style[t] !== undefined) {
            return animations[t];
          }
        }
      })(document.createElement('div'));

      this.addClass('animated ' + animationName).one(animationEnd, function () {
        $(this).removeClass('animated ' + animationName);

        if (typeof callback === 'function') callback();
      });

      return this;
    },
  });

  //#region
  function shuffle(array) {
    var currentIndex = array.length, temporaryValue, randomIndex;
    while (0 !== currentIndex) {
      randomIndex = Math.floor(Math.random() * currentIndex);
      currentIndex -= 1;
      temporaryValue = array[currentIndex];
      array[currentIndex] = array[randomIndex];
      array[randomIndex] = temporaryValue;
    }
    return array;
  }
  let animInArray = ['jackInTheBox', 'rollIn', 'zoomInUp', 'zoomIn', 'slideInLeft', 'slideInDown', 'lightSpeedIn',
    'rotateIn', 'flipInX', 'flipInY', 'fadeIn', 'fadeInUp', 'fadeInDown', 'bounceInUp', 'bounceInDown'];
  let animOutArray = ['rollOut', 'zoomOutUp', 'zoomOut', 'slideOutLeft', 'slideOutDown', 'lightSpeedOut',
    'rotateOut', 'flipOutX', 'flipOutY', 'fadeOut', 'fadeOutUp', 'fadeOutDown', 'bounceOutUp', 'bounceOutDown'];
  let attAnimArray = ['bounce', 'flash', 'pulse', 'rubberBand', 'shake', 'swing', 'tada', 'wobble', 'jello'];
  let randomOutArray = new Array();
  let numberInput = $('input[name="number"]');
  let button = $('input[name="losuj"]');
  let eT = 30;
  let r = 0;
  function randomOut(element, random) {
    randomOutArray.push(element);
    if (randomOutArray.length == numberInput.val()) {
      r = random;
      let timeOuts = new Array();
      shuffle(randomOutArray);
      $(randomOutArray).each((index) => {
        timeOuts[index] = new Promise((resolve, reject) => {
          setTimeout((jqObj) => {
            if ($(randomOutArray[index]).html() != r) {
              jqObj.animateCss(animOutArray[Math.floor(Math.random() * animOutArray.length)], () => {
                $(randomOutArray[index]).addClass('non-visible');
              });
            }
            resolve();
          }, index * eT, $(randomOutArray[index]));
        });
      });
      Promise.all(timeOuts).then(() => {
        console.log('kurly');
        $(randomOutArray[randomOutArray.map(function (x) { return $(x).html(); }).indexOf(r.toString())]).addClass('zoom');
      });
    }
  }
  //#endregion

  button.click(() => {
    let number = parseInt(numberInput.val());
    if (isNaN(number)) {
      alert('Proszę podać liczbe!');
    } else {
      if (number > 40 || number <= 0) alert('Liczba musi być mniejsza niż 40 i większa od 0.');
      else {
        let speed = $('input[name="speed"]').val();
        if (speed > 300 || speed < 50) alert('Proszę wprowadzić prawidłową szybkość.');
        else {
          eT = speed;
          let initialSection = $('section[name="initial"]');
          let mainSection = $('section[name="main"]');
          initialSection.animateCss('bounceOutUp', () => {
            initialSection.addClass('away');
            let tableChildren = $('table').find('tr').find('td');
            let usedNumbers = tableChildren.slice(0, number);
            $(usedNumbers).addClass('non-visible');
            let diff = $(tableChildren).not(usedNumbers).get();
            $(diff).hide();
            mainSection.removeClass('away');
            mainSection.animateCss('fadeInUp', () => {
              let random = Math.floor(Math.random() * number) + 1;
              console.log(random);
              let timeOuts = new Array();
              usedNumbers.each(function (index) {
                timeOuts[index] = new Promise((resolve, reject) => {
                  setTimeout((jqObj) => {
                    jqObj.animateCss(animInArray[Math.floor(Math.random() * animInArray.length)]);
                    jqObj.removeClass('non-visible');
                    jqObj.css('color', "#" + ((1 << 24) * Math.random() | 0).toString(16));
                    resolve();
                  }, index * eT, $(this));
                })
              });
              Promise.all(timeOuts).then(() => {
                usedNumbers.each(function (index) {
                  timeOuts[index] = new Promise((resolve, reject) => {
                    setTimeout((jqObj) => {
                      jqObj.css('color', "#" + ((1 << 24) * Math.random() | 0).toString(16));
                      timeOuts[index] = setTimeout((jqObjx) => {
                        jqObjx.css('color', "#" + ((1 << 24) * Math.random() | 0).toString(16));
                        jqObjx.animateCss(attAnimArray[Math.floor(Math.random() * attAnimArray.length)]);
                        timeOuts[index] = setTimeout((jqObjxx) => {
                          randomOut(jqObjxx, random);
                          resolve();
                        }, index * eT, $(this))
                      }, index * eT, $(this));
                    }, index * 0.1 * eT, $(this));
                  });
                });
              });
            });
          });
        }
      }
    }
  });
});
