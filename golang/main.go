package main

import (
	"googlemaps.github.io/maps"
	"context"
	"fmt"
	"log"
)

func GmapsClient() *maps.Client {

	client, err := maps.NewClient(maps.WithAPIKey("xxx"))
	if err != nil {
		log.Fatalf("fatal error gmaps: %s", err)
	}

	return client
}


func GetCityByLocation(lat float64, lng float64) (string, error) {
	c := GmapsClient()

	r := &maps.GeocodingRequest{
		LatLng:     &maps.LatLng{Lat: lat, Lng: lng},
		ResultType: []string{"administrative_area_level_2"},
		Language:   "id",
	}
	result, err := c.ReverseGeocode(context.Background(), r)
	cityName := result[0].AddressComponents[0].LongName

	return cityName, err
}


func main() {
	var long  = 109.7345
	var lat = -6.9093333

	city,err := GetCityByLocation(lat,long)
	if err!=nil {

	}
	fmt.Println(city)
}