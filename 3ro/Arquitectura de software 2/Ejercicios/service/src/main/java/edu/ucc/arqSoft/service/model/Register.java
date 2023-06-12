package edu.ucc.arqSoft.service.model;

import java.util.Set;
import java.sql.Timestamp;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.FetchType;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;
import org.hibernate.annotations.Proxy;
import org.hibernate.validator.constraints.Range;

import edu.ucc.arqSoft.service.common.model.GenericObject;

@Entity
@Table(name = "Register")
@Proxy(lazy = false)
public class Register extends GenericObject{
	@NotNull
	@Range(min = 1, max = 100)
	@Column(name = "Temperature")
	private int temperature;
	
	@NotNull
	@Range(min = 0, max = 100)
	@Column(name = "Pressure")
	private float pressure;
	
	@NotNull
	@Range(min = 0, max = 100)
	@Column(name = "Wind")
	private int wind;

	@NotNull
	@Column(name = "Timestamp")
	private Timestamp timestamp;
	
	@NotNull
	@ManyToOne(fetch = FetchType.LAZY)
	@JoinColumn(name="Sensor_ID")
	private Sensor sensor;

	/*
	@OneToMany(mappedBy="pelicula", fetch = FetchType.LAZY)
	private Set<Alquiler> alquileres
	*/
	
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

	public Sensor getSensor() {
		return sensor;
	}

	public void setSensor(Sensor sensor) {
		this.sensor = sensor;
	}
	
	
}