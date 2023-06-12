package edu.ucc.arqSoft.service.dto;
import java.sql.Timestamp;

import edu.ucc.arqSoft.service.model.Sensor;

public class RegisterRequestDto {
	
	private int temperature;
	
	private float pressure;
	
	private int wind;
	
	private Timestamp timestamp;
	
	private long sensor_id;

	private String locationName;

	public int getTemperature() {
		return temperature;
	}

	public void setTemperature(int temperature) {
		this.temperature = temperature;
	}

	public float getPressure() {
		return pressure;
	}

	public void setPressure(float pressure) {
		this.pressure = pressure;
	}

	public int getWind() {
		return wind;
	}

	public void setWind(int wind) {
		this.wind = wind;
	}

	public Timestamp getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(Timestamp timestamp) {
		this.timestamp = timestamp;
	}

	public long getSensor_id() {
		return sensor_id;
	}

	public void setSensor_id(long sensor_id) {
		this.sensor_id = sensor_id;
	}

	public String getLocationName() {
		return locationName;
	}

	public void setSensor(String locationName) {
		this.locationName = locationName;
	}
	
	
}	