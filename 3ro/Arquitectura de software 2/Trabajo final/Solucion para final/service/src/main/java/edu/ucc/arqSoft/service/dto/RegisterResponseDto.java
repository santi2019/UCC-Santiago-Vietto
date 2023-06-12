package edu.ucc.arqSoft.service.dto;

public class RegisterResponseDto {
	
	private int temperature;
	
	private float pressure;
	
	private int wind;
	
	private String timestamp;
	
	private Long sensor_id;

	private String sensorLocation;
	
	private Long id;

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

	public String getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(String timestamp) {
		this.timestamp = timestamp;
	}

	public long getSensor_id() {
		return sensor_id;
	}

	public void setSensor_id(long sensor_id) {
		this.sensor_id = sensor_id;
	}

	public String getSensorLocation() {
		return sensorLocation;
	}

	public void setSensorLocation(String sensorLocation) {
		this.sensorLocation = sensorLocation;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}
}
