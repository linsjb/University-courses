window.onload = function () {
  let backgroundColors = [
    {value: '#2196F3', name: 'Blå'},
    {value: '#FF9800', name: 'Orange'},
    {value: '#4CAF50', name: 'Grön'}
  ];

  let textColors = [
    {value: '#212121', name: 'Svart'},
    {value: '#0D47A1', name: 'Blå'},
    {value: '#1B5E20', name: 'Grön'}
  ];

  let textFamilies = [
    {value: 'timesNewRoman', name: 'Times new roman'},
    {value: 'arial', name: 'Arial'}
  ];

  let cardBackgroundColor = document.getElementById('backgroundColor');
  let cardTextColor = document.getElementById('textColor');
  let cardTextFamily = document.getElementById('fontFamily');

  // Map background-colors to combobox
  backgroundColors.map((background) => {
    let optionElement = document.createElement('option');
    optionElement.setAttribute('value', background.value);

    let text = document.createTextNode(background.name);
    optionElement.appendChild(text);
    cardBackgroundColor.appendChild(optionElement);
  });

  // Map text colors to combobox
  textColors.map((textColor) => {
    let optionElement = document.createElement('option');
    optionElement.setAttribute('value', textColor.value);

    let text = document.createTextNode(textColor.name);
    optionElement.appendChild(text);
    cardTextColor.appendChild(optionElement);
  });

  // Map font families to combobox
  textFamilies.map((fontFamily) => {
    let optionElement = document.createElement('option');
    optionElement.setAttribute('value', fontFamily.value);

    let text = document.createTextNode(fontFamily.name);
    optionElement.appendChild(text);
    cardTextFamily.appendChild(optionElement);
  });

  let printButton = document.getElementById('printButton');
  let resetButton = document.getElementById('resetButton');

  let inputFields = document.getElementsByClassName('cardDesignInputFields');
  let previewElements = document.getElementsByClassName('previewCardContent');

  let previewCard = document.getElementById('cardPreview');

  printButton.addEventListener('click', () => {
    document.getElementById('cardDesigner').style.display = 'none';
    document.getElementById('cardPreview').style.display = 'block';

    let selectedBackground = cardBackgroundColor.options[cardBackgroundColor.selectedIndex].value;
    previewCard.style.backgroundColor = selectedBackground;

    let selectedTextColor = cardTextColor.options[cardTextColor.selectedIndex].value;
    previewCard.style.color = selectedTextColor;

    let selectedFont = cardTextFamily.options[cardTextFamily.selectedIndex].value;
    previewCard.style.fontFamily = selectedFont;

    for (let i = 0; i < previewElements.length; i++) {
      previewElements[i].innerHTML = inputFields[i].value;
    }
  });

  resetButton.addEventListener('click', () => {
    for (let i = 0; i < inputFields.length; i++) {
      inputFields[i].value = '';
    }
    inputFields[0].focus();
  });
};
