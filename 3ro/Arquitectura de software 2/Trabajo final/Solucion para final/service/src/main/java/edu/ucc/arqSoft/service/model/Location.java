/*package edu.ucc.arqSoft.service.model;

public enum Location {
	JUJUY, MENDOZA, CORDOBA, SANTACRUZ, MISIONES;
}
*/
package edu.ucc.arqSoft.service.model;

import java.util.Set;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;
import org.hibernate.annotations.Proxy;
import org.hibernate.validator.constraints.Range;

import edu.ucc.arqSoft.service.common.model.GenericObject;

@Entity
@Table(name = "Location")
@Proxy(lazy = false)
public class Location extends GenericObject{
	@NotNull
	@Range(min = 1, max = 100)
	@Column(name = "Name")
	private String Name;
	
	@NotNull
	@OneToMany(mappedBy="location", fetch = FetchType.LAZY)
	private Set<Sensor> sensors;

	/*
	@OneToMany(mappedBy="pelicula", fetch = FetchType.LAZY)
	private Set<Alquiler> alquileres
	*/
	public void setName(String name) {
		this.Name = name;
	}

	public String getName() {
		return Name;
	}
	
	public Set<Sensor> getSensors() {
	 	return sensors;
	 }

 	public void setSensors(Set<Sensor> sensors) {
	 	this.sensors = sensors;
 	}

}